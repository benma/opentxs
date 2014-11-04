/************************************************************
 *
 *  MessageProcessor.cpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <opentxs/server/ServerSettings.hpp>
#include <opentxs/server/ServerLoader.hpp>
#include <opentxs/server/MessageProcessor.hpp>
#include <opentxs/server/OTServer.hpp>
#include <opentxs/server/ClientConnection.hpp>
#include <opentxs/core/OTLog.hpp>
#include <opentxs/core/OTMessage.hpp>
#include <opentxs/core/String.hpp>
#include <opentxs/core/OTSettings.hpp>
#include <opentxs/core/util/OTDataFolder.hpp>
#include <opentxs/core/crypto/OTEnvelope.hpp>
#include <opentxs/core/util/Timer.hpp>
#include <opentxs/ext/OTSocket.hpp>

namespace
{

enum {
    SERVER_DEFAULT_LATENCY_SEND_MS = 5000,
    SERVER_DEFAULT_LATENCY_SEND_NO_TRIES = 2,
    SERVER_DEFAULT_LATENCY_RECEIVE_MS = 5000,
    SERVER_DEFAULT_LATENCY_RECEIVE_NO_TRIES = 2,
    SERVER_DEFAULT_LATENCY_DELAY_AFTER = 50,
    SERVER_DEFAULT_IS_BLOCKING = 0
};

} // namespace

namespace opentxs
{

MessageProcessor::MessageProcessor(ServerLoader& loader)
    : server_(loader.getServer())
    , socket_()
{
    init(loader.getPort());
}

void MessageProcessor::init(int port)
{
    String configFolderPath = "";
    if (!OTDataFolder::GetConfigFilePath(configFolderPath)) {
        OT_FAIL;
    }
    OTSettings settings(configFolderPath);

    settings.Reset();
    if (!settings.Load()) {
        OT_FAIL;
    }

    OTSocket::Defaults socketDefaults(
        SERVER_DEFAULT_LATENCY_SEND_MS, SERVER_DEFAULT_LATENCY_SEND_NO_TRIES,
        SERVER_DEFAULT_LATENCY_RECEIVE_MS,
        SERVER_DEFAULT_LATENCY_RECEIVE_NO_TRIES,
        SERVER_DEFAULT_LATENCY_DELAY_AFTER, SERVER_DEFAULT_IS_BLOCKING);

    if (!socket_.Init(socketDefaults, &settings)) {
        OT_FAIL;
    }

    if (!settings.Save()) {
        OT_FAIL;
    }
    settings.Reset();

    if (!socket_.NewContext()) {
        OT_FAIL;
    }

    if (port == 0) {
        OT_FAIL;
    }
    String bindPath;
    bindPath.Format("%s%d", "tcp://*:", port);

    if (!socket_.Listen(bindPath.Get())) {
        OT_FAIL;
    }
}

void MessageProcessor::run()
{
    for (;;) {
        // =-=-=- HEARTBEAT -=-=-=
        //
        // The Server now processes certain things on a regular basis.
        // ProcessCron is what gives it the opportunity to do that.
        // All of the Cron Items (including market trades, payment plans, smart
        // contracts...)
        // they all have their hooks here...
        //
        // Internally this is smart enough to know how often to actually
        // activate itself.
        server_->ProcessCron();
        // Most often it just returns doing nothing (waiting for its timer.)
        // Wait for client http requests (and process replies out to them.)
        // Number of requests to process per heartbeat:
        // ServerSettings::GetHeartbeatNoRequests()
        //
        // Loop: process up to 10 client requests, then sleep for 1/10th second.
        // That's a total of 100 requests per second. Can the computers handle
        // it?
        // Is it too much or too little? Todo: load testing.
        //
        // Then: check for shutdown flag.
        //
        // Then: go back to the top ("do") and repeat the loop.... process cron,
        // process 10 client requests, sleep, check for shutdown, etc.

        Timer t;
        t.start();
        double startTick = t.getElapsedTimeInMilliSec();

        // PROCESS X NUMBER OF REQUESTS (THIS PULSE.)
        //
        // Theoretically the "number of requests" that we process EACH PULSE.
        // (The timing code here is still pretty new, need to do some load
        // testing.)
        for (int i = 0; i < ServerSettings::GetHeartbeatNoRequests(); i++) {
            std::string messageString;

            // With 100ms heartbeat, receive will try 100 ms, then 200 ms, then
            // 400 ms, total of 700.
            // That's about 15 Receive() calls every 10 seconds. Therefore if I
            // want the ProcessCron()
            // to trigger every 10 seconds, I need to set the cron interval to
            // roll over every 15 heartbeats.
            // Therefore I will be using a real Timer for Cron, instead of the
            // damn intervals.
            bool received = socket_.Receive(messageString);

            if (received) {
                if (messageString.size() <= 0) {
                    OTLog::Error("server main: Received a message, but of 0 "
                                 "length or less. Weird. (Skipping it.)\n");
                }
                else {
                    std::string reply;
                    bool shouldDisconnect = processMessage(messageString, reply);
                    static int msg_id=1;
                    TRACE_MESSAGE(reply, std::string("message_") + std::to_string (msg_id++));
                    if (reply.length() <= 0 || shouldDisconnect) {
                        OTLog::vOutput(
                            0, "server main: ERROR: Unfortunately, not every "
                               "client request is "
                               "legible or worthy of a server response. :-)  "
                               "Msg:\n\n%s\n\n",
                            messageString.c_str());

                        socket_.Listen();
                    }
                    else {
                        bool successSending = socket_.Send(reply.c_str());

                        if (!successSending) {
                            OTLog::vError("server main: Socket ERROR: failed "
                                          "while trying to send reply "
                                          "back to client! \n\n "
                                          "MESSAGE:\n%s\n\nREPLY:\n%s\n\n",
                                          messageString.c_str(), reply.c_str());
                        }
                    }
                }
            }
        }

        // IF the time we had available wasn't all used up -- if some of it is
        // still available, then SLEEP until we reach the NEXT PULSE. (In
        // practice, we will probably use TOO MUCH time, not too little--but
        // then again OT isn't ALWAYS processing a message. There could be
        // plenty of dead time in between...)
        double endTick = t.getElapsedTimeInMilliSec();
        int64_t elapsed = static_cast<int64_t>(endTick - startTick);

        if (elapsed < ServerSettings::GetHeartbeatMsBetweenBeats()) {
            int64_t ms = ServerSettings::GetHeartbeatMsBetweenBeats() - elapsed;
            OTLog::SleepMilliseconds(ms);
        }

        if (server_->IsFlaggedForShutdown()) {
            OTLog::Output(0, "opentxs server is shutting down gracefully.\n");
            break;
        }
    }
}

bool MessageProcessor::processMessage(const std::string& messageString,
                                      std::string& reply)
{
    if (messageString.size() < 1) return false;

    // First we grab the client's message
    OTASCIIArmor ascMessage;
    ascMessage.MemSet(messageString.data(), messageString.size());

    OTEnvelope envelope;
    if (!envelope.SetAsciiArmoredData(ascMessage)) {
        OTLog::vError("Error retrieving envelope.\n");
        return true;
    }

    // Now the base64 is decoded and the envelope is in binary form again.
    OTLog::vOutput(2, "Successfully retrieved envelope from message.\n");

    // Decrypt the Envelope.
    String envelopeContents;
    if (!envelope.Open(server_->GetServerNym(), envelopeContents)) {
        OTLog::vError("Unable to open envelope.\n");
        return true;
    }

    // All decrypted--now let's load the results into an OTMessage.
    // No need to call message.ParseRawFile() after, since
    // LoadContractFromString handles it.
    OTMessage message;
    if (!envelopeContents.Exists() ||
        !message.LoadContractFromString(envelopeContents)) {
        OTLog::vError("Error loading message from envelope "
                      "contents:\n\n%s\n\n",
                      envelopeContents.Get());
        return true;
    }

    OTMessage replyMessage;
    replyMessage.m_strCommand.Format("@%s", message.m_strCommand.Get());
    // UserID
    replyMessage.m_strNymID = message.m_strNymID;
    // ServerID, a hash of the server contract
    replyMessage.m_strServerID = message.m_strServerID;
    // The default reply. In fact this is probably superfluous
    replyMessage.m_bSuccess = false;

    // By constructing this without a socket, I put it in ZMQ mode,
    // instead of tcp/ssl.
    ClientConnection client;

    OTPseudonym nym(message.m_strNymID);

    bool processedUserCmd = server_->userCommandProcessor_.ProcessUserCommand(
        message, replyMessage, &client, &nym);

    // By optionally passing in &client, the client Nym's public
    // key will be set on it whenever verification is complete. (So
    // for the reply, I'll  have the key and thus I'll be able to
    // encrypt reply to the recipient.)
    if (!processedUserCmd) {
        String s1(message);

        OTLog::vOutput(0, "Unable to process user command: %s\n ********** "
                          "REQUEST:\n\n%s\n\n",
                       message.m_strCommand.Get(), s1.Get());

        // NOTE: normally you would even HAVE a true or false if
        // we're in this block. ProcessUserCommand()
        // is what tries to process a command and then sets false
        // if/when it fails. Until that point, you
        // wouldn't get any server reply.  I'm now changing this
        // slightly, so you still get a reply (defaulted
        // to success==false.) That way if a client needs to re-sync
        // his request number, he will get the false
        // and therefore know to resync the # as his next move, vs
        // being stuck with no server reply (and thus
        // stuck with a bad socket.)
        // We sign the reply here, but not in the else block, since
        // it's already signed in cases where
        // ProcessUserCommand() is a success, by the time that call
        // returns.

        // Since the process call definitely failed, I'm
        replyMessage.m_bSuccess = false;
        // making sure this here is definitely set to
        // false (even though it probably was already.)
        replyMessage.SignContract(server_->GetServerNym());
        replyMessage.SaveContract();

        String s2(replyMessage);

        OTLog::vOutput(0, " ********** RESPONSE:\n\n%s\n\n", s2.Get());
    }
    else {
        // At this point the reply is ready to go, and client
        // has the public key of the recipient...
        OTLog::vOutput(1, "Successfully processed user command: %s.\n",
                       message.m_strCommand.Get());
    }

    // IF ProcessUserCommand returned true, THEN we process the
    // message for the recipient.
    // ELSE IF ProcessUserCommand returned false, YET the PubKey
    // DOES exist, THEN in this case also, we process the message
    // for the recipient.
    //
    // if success + Nym's pub key exists here on server.
    if (processedUserCmd || nym.Server_PubKeyExists()) {
        // The transaction is now processed (or not), and the
        // server's reply message is in replyMessage.
        // Let's seal it up to the recipient's nym (in an envelope)
        // and send back to the user...
        OTEnvelope recipientEnvelope;

        bool sealed =
            client.SealMessageForRecipient(replyMessage, recipientEnvelope);

        if (!sealed) {
            OTLog::vOutput(0, "Unable to seal envelope. (No reply will be "
                              "sent.)\n");
            return true;
        }

        OTASCIIArmor ascReply;
        if (!recipientEnvelope.GetAsciiArmoredData(ascReply)) {
            OTLog::vOutput(
                0,
                "Unable to GetAsciiArmoredData from sealed "
                "envelope int oOTASCIIArmor object. (No reply envelope will be "
                "sent.)\n");
            return true;
        }

        String output;
        bool val = ascReply.Exists() &&
                   ascReply.WriteArmoredString(output, "ENVELOPE");

        if (!val || !output.Exists()) {
            OTLog::vOutput(
                0, "Unable to WriteArmoredString from "
                   "OTASCIIArmor object into OTString object. (No reply "
                   "envelope will be sent.)\n");
            return true;
        }

        reply.assign(output.Get(), output.GetLength());
    }
    // ELSE we send the message in the CLEAR. (As an armored
    // message, instead of as an armored envelope.)
    else {
        String replyString(replyMessage);

        if (!replyString.Exists()) {
            OTLog::vOutput(0, "Failed trying to grab the reply "
                              "in OTString form. "
                              "(No reply message will be sent.)\n");
            return true;
        }

        OTASCIIArmor ascReply(replyString);
        String output;
        bool val =
            ascReply.Exists() && ascReply.WriteArmoredString(output, "MESSAGE");

        if (!val || !output.Exists()) {
            OTLog::vOutput(
                0, "Unable to WriteArmoredString from "
                   "OTASCIIArmor object into OTString object. (No reply "
                   "message will be sent.)\n");
            return true;
        }

        reply.assign(output.Get(), output.GetLength());
    }

    return false;
}

} // namespace opentxs
