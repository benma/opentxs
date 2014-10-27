
import base64
import cgi
import sys

def html_escape(input):
    s = cgi.escape(input) 
    return s.replace('\n', '<br>')

class Line:
    def __init__(self, input, output, link):
#        print "input: ", input 
#        print "output: ", output 
#        print "link: ", link
        self.input = input
        self.output = output
        self.link = link

    def generate(self, lines):
        found = {}
        for l in lines:
            if l == self:
                continue
            start = self.input.find(l.output)
            if start == -1:
                continue
            found[(start, -len(l.output))] = l

        maximum_reached = -1
        result = {}
        for key in sorted(found.keys()):
            if key[0] < maximum_reached:
                continue
            # key[1] is negative
            maximum_reached = key[0] - key[1]
            result[(key[0], maximum_reached)] = found[key]
            # and process also result
            found[key].generate(lines)

        maximum_reached = -1
        for key in sorted(result.keys()):
            if key[0] > maximum_reached + 1:
                result[(maximum_reached + 1, key[0] - 1)] = None
            maximum_reached = key[1]
        
        if maximum_reached < len(self.output):
            result[(maximum_reached + 1, len(self.input))] = None

#        print(self.input)
#        print(found)
#        print(result)
        self.tree = result
        
    def generateHtml(self):
        html = '<table border="1" >'
        for key in sorted(self.tree.keys()):
            html += "<tr>"
            # TODO: escape chars
            html += "<td>" + html_escape(self.input[key[0]:key[1]+1]) + "</td>"
            html += "<td>"
            l = self.tree[key]
            if l:
                html += l.generateHtml()
            html += "</td>"
            if l:
                html += "<td>" + l.link + "</td>"
            else:
                html += "<td></td>"
            html += "</tr>"
        html += "</table>"
        return html

class Message:
    def __init__(self, line):
        self.line = line
        self.lines = []

    def addLine(self, line):
        self.lines.append(line)

    def generateHtml(self):
        self.line.generate(self.lines)
        return self.line.generateHtml()
        
        
def parse_file(filename):
    messages = []
    lines = []
    with open(filename, "r") as f:
        for line in f:
            if not line.startswith("TraceLine:"):
                continue
            ss = line.split(" ", 1)[1]
            s = ss.split(";")
            #print(s)
            if s[1].startswith("message_"):
                l = Line(base64.decodestring(s[0]), s[1], s[2])
                messages.append(Message(l))
                messages[-1].lines = lines
                lines = []
            elif messages:
                l = Line(base64.decodestring(s[0]), base64.decodestring(s[1]), s[2])
                lines.append(l)
    return messages
                        
messages = parse_file(sys.argv[1])

print "<html>\n"
for m in messages:
    print m.generateHtml()
    print "\n"
print "\n<html>\n"
