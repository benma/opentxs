/************************************************************
 *
 *  opentxs.cpp
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

#include "opentxs.hpp"

#include <opentxs/client/CmdAcceptAll.hpp>
#include <opentxs/client/CmdAcceptInbox.hpp>
#include <opentxs/client/CmdAcceptInvoices.hpp>
#include <opentxs/client/CmdAcceptMoney.hpp>
#include <opentxs/client/CmdAcceptPayments.hpp>
#include <opentxs/client/CmdAcceptReceipts.hpp>
#include <opentxs/client/CmdAcceptTransfers.hpp>
#include <opentxs/client/CmdAddAsset.hpp>
#include <opentxs/client/CmdAddServer.hpp>
#include <opentxs/client/CmdAddSignature.hpp>
#include <opentxs/client/CmdCancel.hpp>
#include <opentxs/client/CmdChangePw.hpp>
#include <opentxs/client/CmdCheckNym.hpp>
#include <opentxs/client/CmdClearExpired.hpp>
#include <opentxs/client/CmdClearRecords.hpp>
#include <opentxs/client/CmdConfirm.hpp>
#include <opentxs/client/CmdDecode.hpp>
#include <opentxs/client/CmdDecrypt.hpp>
#include <opentxs/client/CmdDeleteInmail.hpp>
#include <opentxs/client/CmdDeleteOutmail.hpp>
#include <opentxs/client/CmdDeposit.hpp>
#include <opentxs/client/CmdDiscard.hpp>
#include <opentxs/client/CmdEditAccount.hpp>
#include <opentxs/client/CmdEditAsset.hpp>
#include <opentxs/client/CmdEditNym.hpp>
#include <opentxs/client/CmdEditServer.hpp>
#include <opentxs/client/CmdEncode.hpp>
#include <opentxs/client/CmdEncrypt.hpp>
#include <opentxs/client/CmdExchangeBasket.hpp>
#include <opentxs/client/CmdExportCash.hpp>
#include <opentxs/client/CmdExportNym.hpp>
#include <opentxs/client/CmdGetContract.hpp>
#include <opentxs/client/CmdGetMarkets.hpp>
#include <opentxs/client/CmdGetMyOffers.hpp>
#include <opentxs/client/CmdGetOffers.hpp>
#include <opentxs/client/CmdGetReceipt.hpp>
#include <opentxs/client/CmdImportCash.hpp>
#include <opentxs/client/CmdImportNym.hpp>
#include <opentxs/client/CmdInbox.hpp>
#include <opentxs/client/CmdInmail.hpp>
#include <opentxs/client/CmdInpayments.hpp>
#include <opentxs/client/CmdIssueAsset.hpp>
#include <opentxs/client/CmdKillOffer.hpp>
#include <opentxs/client/CmdKillPlan.hpp>
#include <opentxs/client/CmdNewAccount.hpp>
#include <opentxs/client/CmdNewAsset.hpp>
#include <opentxs/client/CmdNewBasket.hpp>
#include <opentxs/client/CmdNewKey.hpp>
#include <opentxs/client/CmdNewNym.hpp>
#include <opentxs/client/CmdNewOffer.hpp>
#include <opentxs/client/CmdNewServer.hpp>
#include <opentxs/client/CmdOutbox.hpp>
#include <opentxs/client/CmdOutmail.hpp>
#include <opentxs/client/CmdOutpayment.hpp>
#include <opentxs/client/CmdPasswordDecrypt.hpp>
#include <opentxs/client/CmdPasswordEncrypt.hpp>
#include <opentxs/client/CmdPayDividend.hpp>
#include <opentxs/client/CmdPayInvoice.hpp>
#include <opentxs/client/CmdProposePlan.hpp>
#include <opentxs/client/CmdRefresh.hpp>
#include <opentxs/client/CmdRefreshAccount.hpp>
#include <opentxs/client/CmdRefreshNym.hpp>
#include <opentxs/client/CmdRegisterNym.hpp>
#include <opentxs/client/CmdSendCash.hpp>
#include <opentxs/client/CmdSendCheque.hpp>
#include <opentxs/client/CmdSendInvoice.hpp>
#include <opentxs/client/CmdSendMessage.hpp>
#include <opentxs/client/CmdSendVoucher.hpp>
#include <opentxs/client/CmdShowAccount.hpp>
#include <opentxs/client/CmdShowAccounts.hpp>
#include <opentxs/client/CmdShowActive.hpp>
#include <opentxs/client/CmdShowAssets.hpp>
#include <opentxs/client/CmdShowBalance.hpp>
#include <opentxs/client/CmdShowBasket.hpp>
#include <opentxs/client/CmdShowCredential.hpp>
#include <opentxs/client/CmdShowCredentials.hpp>
#include <opentxs/client/CmdShowExpired.hpp>
#include <opentxs/client/CmdShowMarkets.hpp>
#include <opentxs/client/CmdShowMint.hpp>
#include <opentxs/client/CmdShowMyOffers.hpp>
#include <opentxs/client/CmdShowNym.hpp>
#include <opentxs/client/CmdShowNyms.hpp>
#include <opentxs/client/CmdShowOffers.hpp>
#include <opentxs/client/CmdShowPayment.hpp>
#include <opentxs/client/CmdShowPurse.hpp>
#include <opentxs/client/CmdShowRecords.hpp>
#include <opentxs/client/CmdShowServers.hpp>
#include <opentxs/client/CmdShowWallet.hpp>
#include <opentxs/client/CmdSignContract.hpp>
#include <opentxs/client/CmdShowWallet.hpp>
#include <opentxs/client/CmdTransfer.hpp>
#include <opentxs/client/CmdTriggerClause.hpp>
#include <opentxs/client/CmdUsageCredits.hpp>
#include <opentxs/client/CmdVerifyReceipt.hpp>
#include <opentxs/client/CmdVerifySignature.hpp>
#include <opentxs/client/CmdWithdrawCash.hpp>
#include <opentxs/client/CmdWithdrawVoucher.hpp>
#include <opentxs/client/CmdWriteCheque.hpp>
#include <opentxs/client/CmdWriteInvoice.hpp>

#include <opentxs/client/OpenTransactions.hpp>
#include <opentxs/client/OTAPI.hpp>

#include <opentxs/core/OTLog.hpp>
#include <opentxs/core/util/OTPaths.hpp>
#include <opentxs/core/Version.hpp>

#include <anyoption/anyoption.hpp>

#include <algorithm>
#include <cctype>
#include <functional>

using namespace opentxs;
using namespace std;

const char* categoryName[] = {
    "Category Error",           "Advanced utilities",    "The user wallet",
    "Misc",                     "Markets (bid/ask)",     "Asset accounts",
    "Dealing with other users", "Financial instruments", "Basket currencies",
    "Pseudonyms"};

CmdBase* cmds[] = {
    new CmdAcceptAll,       new CmdAcceptInbox,     new CmdAcceptInvoices,
    new CmdAcceptMoney,     new CmdAcceptPayments,  new CmdAcceptReceipts,
    new CmdAcceptTransfers, new CmdAddAsset,        new CmdAddServer,
    new CmdAddSignature,    new CmdCancel,          new CmdChangePw,
    new CmdCheckNym,        new CmdClearExpired,    new CmdClearRecords,
    new CmdConfirm,         new CmdDecode,          new CmdDecrypt,
    new CmdDeleteInmail,    new CmdDeleteOutmail,   new CmdDeposit,
    new CmdDiscard,         new CmdEditAccount,     new CmdEditAsset,
    new CmdEditNym,         new CmdEditServer,      new CmdEncode,
    new CmdEncrypt,         new CmdExchangeBasket,  new CmdExportCash,
    new CmdExportNym,       new CmdGetContract,     new CmdGetMarkets,
    new CmdGetMyOffers,     new CmdGetOffers,       new CmdGetReceipt,
    new CmdImportCash,      new CmdImportNym,       new CmdInbox,
    new CmdInmail,          new CmdInpayments,      new CmdIssueAsset,
    new CmdKillOffer,       new CmdKillPlan,        new CmdNewAccount,
    new CmdNewAsset,        new CmdNewKey,          new CmdNewNym,
    new CmdNewOffer,        new CmdNewServer,       new CmdOutbox,
    new CmdOutmail,         new CmdNewBasket,       new CmdOutpayment,
    new CmdPasswordDecrypt, new CmdPasswordEncrypt, new CmdPayDividend,
    new CmdPayInvoice,      new CmdProposePlan,     new CmdRefresh,
    new CmdRefreshAccount,  new CmdRefreshNym,      new CmdRegisterNym,
    new CmdSendCash,        new CmdSendCheque,      new CmdSendInvoice,
    new CmdSendMessage,     new CmdSendVoucher,     new CmdShowAccount,
    new CmdShowAccounts,    new CmdShowActive,      new CmdShowAssets,
    new CmdShowBalance,     new CmdShowBasket,      new CmdShowCredential,
    new CmdShowCredentials, new CmdShowExpired,     new CmdShowMarkets,
    new CmdShowMint,        new CmdShowMyOffers,    new CmdShowNym,
    new CmdShowNyms,        new CmdShowOffers,      new CmdShowPayment,
    new CmdShowPurse,       new CmdShowRecords,     new CmdShowServers,
    new CmdShowWallet,      new CmdSignContract,    new CmdTransfer,
    new CmdTriggerClause,   new CmdUsageCredits,    new CmdVerifyReceipt,
    new CmdVerifySignature, new CmdWithdrawCash,    new CmdWithdrawVoucher,
    new CmdWriteCheque,     new CmdWriteInvoice,    nullptr};

Opentxs::Opentxs()
{
    OTAPI_Wrap::AppInit();
}

Opentxs::~Opentxs()
{
    OTAPI_Wrap::AppCleanup();
}

string& Opentxs::ltrim(string& s)
{
    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string& Opentxs::rtrim(string& s)
{
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());
    return s;
}

string& Opentxs::trim(string& s)
{
    return ltrim(rtrim(s));
}

const char* Opentxs::getOption(AnyOption& opt, const char* optionName,
                               const char* defaultName)
{
    // can we get the default value from the command line?
    const char* value = opt.getValue(optionName);
    if (value != nullptr) {
        otWarn << "Option  " << optionName << ": " << value << "\n";
        return value;
    }

    // can we get the default value from the options file?
    if (nullptr != defaultName) {
        value = opt.getValue(defaultName);
        if (value != nullptr) {
            otWarn << "Default " << optionName << ": " << value << "\n";
            return value;
        }
    }

    // clear option value
    return "";
}

void Opentxs::loadOptions(AnyOption& opt)
{
    OTString configPath(OTPaths::AppDataFolder());
    bool configPathFound = configPath.Exists() && 3 < configPath.GetLength();
    OT_ASSERT_MSG(configPathFound,
                  "RegisterAPIWithScript: Must set Config Path first!\n");
    otWarn << "Using configuration path: " << configPath << "\n";

    opt.addUsage("");
    opt.addUsage(" Opentxs CLI Usage:  ");
    opt.addUsage("");

    opt.setCommandFlag("echocommand");
    opt.setCommandFlag("echoexpand");
    opt.setCommandFlag("errorlist");
    opt.setCommandFlag("noprompt");
    opt.setCommandFlag("test");

    opt.setCommandOption("args");
    opt.setCommandOption("myacct");
    opt.setCommandOption("mynym");
    opt.setCommandOption("mypurse");
    opt.setCommandOption("hisacct");
    opt.setCommandOption("hisnym");
    opt.setCommandOption("hispurse");
    opt.setCommandOption("server");

    // for options that will be checked only from the CLI option file
    opt.setFileOption("defaultserver");
    opt.setFileOption("defaultmyacct");
    opt.setFileOption("defaultmynym");
    opt.setFileOption("defaultmypurse");
    opt.setFileOption("defaulthisacct");
    opt.setFileOption("defaulthisnym");
    opt.setFileOption("defaulthispurse");

    OTString optionsFile("command-line-ot.opt"), iniFileExact;
    bool buildFullPathSuccess =
        OTPaths::RelativeToCanonical(iniFileExact, configPath, optionsFile);
    OT_ASSERT_MSG(buildFullPathSuccess, "Unable to set Full Path");

    opt.processFile(iniFileExact.Get());
}

int Opentxs::opentxsCommand(const string& command, AnyOption& opt)
{
    if ("exit" == command || "quit" == command) {
        return -2;
    }

    if ("version" == command) {
        otOut << "opentxs " << OPENTXS_VERSION_STRING << "\n";
        otOut << "Copyright (C) 2014 Open Transactions Developers\n";
        return 0;
    }

    if ("list" == command) {
        otOut << "\nCommands:\n\n";
        for (int32_t i = 0; cmds[i] != nullptr; i++) {
            CmdBase& cmd = *cmds[i];
            otOut << (cmd.getCommand() + spaces18).substr(0, 18);
            if (i % 4 == 3) {
                otOut << "\n";
            }
        }
        otOut << "\n";
        return 0;
    }

    if ("help" == command) {
        // create category groups
        string categoryGroup[catLast];
        for (int i = 1; i < catLast; i++) {
            categoryGroup[i] = string("\n ") + categoryName[i] + ":\n";
        }

        // add commands to their category group
        otOut << "\nCommands:\n";
        for (int32_t i = 0; cmds[i] != nullptr; i++) {
            CmdBase& cmd = *cmds[i];
            categoryGroup[cmd.getCategory()] +=
                (cmd.getCommand() + spaces18).substr(0, 18) + cmd.getHelp() +
                "\n";
        }

        // print all category groups
        for (int i = 1; i < catLast; i++) {
            otOut << categoryGroup[i];
        }

        return 0;
    }

    // all other commands.
    for (int32_t i = 0; cmds[i] != nullptr; i++) {
        CmdBase& cmd = *cmds[i];
        if (command == cmd.getCommand()) {
            return runCommand(cmd);
        }
    }

    otOut << "\nUndefined command: \"" << command << "\" -- Try 'list'.\n\n";
    return -1;
}

int Opentxs::processCommand(OT_ME& madeEasy, AnyOption& opt)
{
    string command = opt.getArgv(0);
    for (int32_t i = 0; cmds[i] != nullptr; i++) {
        CmdBase& cmd = *cmds[i];
        if (command == cmd.getCommand()) {
            return runCommand(cmd);
        }
    }

    otOut << "Expecting a single opentxs command.\n";

    // typedef unique_ptr<OTVariable> GlobalVar;
    // GlobalVar varArgs(setGlobalVar(madeEasy, "Args", argArgs));
    // GlobalVar varHisAcct(setGlobalVar(madeEasy, "HisAcct", argHisAcct));
    // GlobalVar varHisNym(setGlobalVar(madeEasy, "HisNym", argHisNym));
    // GlobalVar varHisPurse(setGlobalVar(madeEasy, "HisPurse", argHisPurse));
    // GlobalVar varMyAcct(setGlobalVar(madeEasy, "MyAcct", argMyAcct));
    // GlobalVar varMyNym(setGlobalVar(madeEasy, "MyNym", argMyNym));
    // GlobalVar varMyPurse(setGlobalVar(madeEasy, "MyPurse", argMyPurse));
    // GlobalVar varServer(setGlobalVar(madeEasy, "Server", argServer));

    // OTAPI_Func::CopyVariables();

    return -1;
}

int Opentxs::run(int argc, char* argv[])
{
    if (OTAPI_Wrap::OTAPI() == nullptr) return -1;

    OTAPI_Wrap::OTAPI()->LoadWallet();

    map<string, string> macros;
    vector<int> errorLineNumbers;
    vector<string> errorCommands;

    OT_ME madeEasy;

    newArgc = argc;
    newArgv = argv;

    AnyOption opt;
    loadOptions(opt);
    opt.processCommandArgs(argc, argv);

    // is there a command on the command line?
    if (opt.getArgc() != 0) {
        expectFailure = false;
        return processCommand(madeEasy, opt);
    }

    int lineNumber = 0;
    bool echoCommand = opt.getFlag("echocommand") || opt.getFlag("test");
    bool echoExpand = opt.getFlag("echoexpand") || opt.getFlag("test");
    bool noPrompt = opt.getFlag("noprompt") || opt.getFlag("test");
    int processed = 0;
    while (true) {
        // get next command line from input stream
        if (!noPrompt) {
            cout << "\nopentxs> ";
        }
        string cmd;
        getline(cin, cmd);

        // end of file stops processing commands
        if (cin.eof()) {
            break;
        }

        lineNumber++;

        // quit/exit the command loop?
        cmd = trim(cmd);
        if (echoCommand) {
            cout << cmd << endl;
        }

        if (cmd == "quit" || cmd == "exit") {
            break;
        }

        // empty lines and lines starting with a hash character are seen as
        // comments
        if (cmd.size() == 0 || cmd[0] == '#') {
            continue;
        }

        string originalCmd = cmd;

        // lines starting with a dollar sign character denote the definition of
        // a macro of the form: $macroName = macroValue
        // whitespace around the equal sign is optional
        // <macroName> can be any combination of A-Z, a-z, 0-9, or _
        // <macroValue> is anything after the equal sign and whitespace-trimmed
        // note that <macroValue> can be an empty string
        // note that the dollar sign itself is part of the immediately following
        // macro name
        // note that a macro value stays valid for the entire lifetime of the
        // command loop
        // note that macro expansion is done on the command line before
        // processing the line this means that a macro is allowed to contain
        // command line escape characters
        // note that macro expansion is recursive until no expansions are found
        // any more this means that a macro is allowed to contain other macros
        if (cmd[0] == '$') {
            // determine the macro name
            size_t nameLength = 1;
            while (nameLength < cmd.length() &&
                   (isalnum(cmd[nameLength]) || cmd[nameLength] == '_')) {
                nameLength++;
            }
            string macroName = cmd.substr(0, nameLength);

            // skip whitespace
            size_t i = nameLength;
            while (i < cmd.length() && isspace(cmd[i])) {
                i++;
            }

            if (i == cmd.length() || cmd[i] != '=') {
                otOut << "\n\n***ERROR***\n"
                         "Expected macro definition of the form: "
                         "$macroName = macroValue\n"
                         "Command was: " << cmd;
                continue;
            }

            // remainder of line after trimming whitespace is macro value
            string macroValue = cmd.substr(i + 1);
            macros[macroName] = trim(macroValue);
            continue;
        }

        // now replace any macro in the command line with its value
        // unknown macro names will cause an error message instead of command
        // execution
        // note that all macro names are 'maximum munch'
        int expansions = 0;
        for (size_t macro = cmd.find_first_of("$"); macro != string::npos;
             macro = cmd.find_first_of("$", macro + 1)) {
            // first see if this is an escaped literal
            if (macro > 0 && cmd[macro - 1] == '\\') {
                continue;
            }

            // gather rest of macro name 'maximum munch'
            size_t macroEnd = macro + 1;
            while (macroEnd < cmd.length() &&
                   (isalnum(cmd[macroEnd]) || cmd[macroEnd] == '_')) {
                macroEnd++;
            }

            // has this macro been defined?
            string macroName = cmd.substr(macro, macroEnd - macro);
            auto found = macros.find(macroName);
            if (found == macros.end()) {
                otOut << "\n\n***ERROR***\n"
                         "Macro expansion failed.\n"
                         "Unknown macro: " << macroName
                      << "\n"
                         "Command was: " << cmd;
                expansions = 100;
                break;
            }

            string& macroValue = found->second;

            // limit to 100 expansions to avoid endless recusion loop
            expansions++;
            if (expansions > 100) {
                otOut << "\n\n***ERROR***\n"
                         "Macro expansion failed.\n"
                         "Too many expansions at macro: " << macroName
                      << "\n"
                         "Command was: " << cmd;
                break;
            }

            // limit to 10000 characters to avoid crazy recursive expansions
            if (cmd.length() + macroValue.length() > 10000) {
                otOut << "\n\n***ERROR***\n"
                         "Macro expansion failed.\n"
                         "Command length exceeded at macro: " << macroName
                      << "\n"
                         "Macro value is: " << macroValue
                      << "\n"
                         "Command was: " << cmd;
                expansions = 100;
                break;
            }

            // expand the command line
            cmd = cmd.substr(0, macro) + macroValue + cmd.substr(macroEnd);
        }

        if (echoExpand && cmd != originalCmd) {
            otOut << cmd << endl;
        }

        // skip command when anything during macro expansion failed
        if (expansions > 99) {
            continue;
        }

        // '!' indicates that we expect this command to fail
        //     which is very useful for running a test script
        expectFailure = cmd[0] == '!';

        // Parse command string into its separate parts so it can be passed as
        // an argc/argv combo
        // Whitespace separates args as usual.
        // To include whitespace in an arg surround the entire arg with double
        // quotes
        // An unterminated double-quoted arg will auto-terminate at end of line
        // All characters are taken literal except for: double quote, dollar
        // sign, and backslash
        // To take any character literal, precede it with a backslash
        vector<string> arguments;

        // add original command name
        arguments.push_back(argv[0]);

        // set up buffer that will receive the separate arguments
        char* buf = new char[cmd.length() + 1];
        char* arg = buf;

        // start at actual command
        size_t i = expectFailure ? 1 : 0;
        while (i < cmd.length()) {
            // skip any whitespace
            while (i < cmd.length() && isspace(cmd[i])) {
                i++;
            }
            if (i == cmd.length()) {
                // it was trailing whitespace; we're done
                break;
            }

            // remember where we start this new argument in the buffer
            char* start = arg;

            // unquoted argument?
            if (cmd[i] != '"') {
                // take everything until end of line or next whitespace
                while (i < cmd.length() && !isspace(cmd[i])) {
                    // unescaped literal character?
                    if (cmd[i] != '\\') {
                        // yep, add to buffer and go for next
                        *arg++ = cmd[i++];
                        continue;
                    }

                    // take next character literal unless it was the end of line
                    // in which case we simply add the backslash as a literal
                    // character
                    *arg++ = i < cmd.length() ? cmd[i++] : '\\';
                }

                // end of argument reached, terminate an add to arguments array
                *arg++ = '\0';
                arguments.push_back(start);

                // look for next argument
                continue;
            }

            // double quoted argument, skip the quote
            i++;

            // take everything until end of line or next double quote
            while (i < cmd.length() && cmd[i] != '"') {
                // unescaped literal character?
                if (cmd[i] != '\\') {
                    // yep, add to buffer and go for next
                    *arg++ = cmd[i++];
                    continue;
                }

                // take next character literal unless it was the end of line
                // in which case we simply add the backslash as a literal
                // character
                *arg++ = i < cmd.length() ? cmd[i++] : '\\';
            }

            // end of argument reached, terminate an add to arguments array
            *arg++ = '\0';
            arguments.push_back(start);

            // skip terminating double quote or end of line
            i++;
        }

        // set up a new argc/argv combo
        newArgc = arguments.size();
        newArgv = new char* [newArgc];
        for (int i = 0; i < newArgc; i++) {
            newArgv[i] = const_cast<char*>(arguments[i].c_str());
        }

        // preprocess the command line
        AnyOption opt;
        loadOptions(opt);
        opt.processCommandArgs(newArgc, newArgv);

        cout << "\n";
        if (expectFailure != (0 != processCommand(madeEasy, opt))) {
            errorLineNumbers.push_back(lineNumber);
            errorCommands.push_back(originalCmd);
            otOut << "\n\n***ERROR***\n"
                  << (expectFailure ? "Expected command to fail.\nSucceeding"
                                    : "Failed") << " command was: " << cmd;
        }

        delete[] newArgv;
        delete[] buf;

        newArgc = 0;
        newArgv = nullptr;

        otOut << "\n\n";
        processed++;
    }

    int failed = errorLineNumbers.size();
    cout << "\n\n" << processed << " commands were processed.\n" << failed
         << " commands failed.\n" << endl;

    if (opt.getFlag("errorList") || opt.getFlag("test")) {
        for (size_t i = 0; i < errorLineNumbers.size(); i++) {
            cout << "\nFailed line " << errorLineNumbers[i] << ": "
                 << errorCommands[i] << endl;
        }
    }

    return failed == 0 ? 0 : -1;
}

int Opentxs::runCommand(CmdBase& cmd)
{
    auto argNames = cmd.extractArgumentNames();

    AnyOption options;
    for (size_t i = 0; i < argNames.size(); i++) {
        if (!options.findOption(argNames[i].c_str())) {
            options.setCommandOption(argNames[i].c_str());
        }
    }

    loadOptions(options);
    options.processCommandArgs(newArgc, newArgv);

    map<string, string> arguments;
    for (size_t i = 0; i < argNames.size(); i++) {
        const char* optionName = argNames[i].c_str();
        const char* value = options.getValue(optionName);
        if (value != nullptr) {
            arguments[argNames[i]] = value;
            continue;
        }

        static const string defaultPrefix = "default";
        static const string haveDefault[] = {"hisacct", "hisnym", "hispurse",
                                             "myacct",  "mynym",  "mypurse",
                                             "server",  ""};

        // can we get the argument value from the option file?
        for (int i = 0; haveDefault[i] != ""; i++) {
            if (haveDefault[i] == optionName) {
                value = options.getValue((defaultPrefix + optionName).c_str());
                if (value != nullptr) {
                    arguments[argNames[i]] = value;
                }
                break;
            }
        }
    }

    bool success = cmd.run(arguments);
    if (!success && !expectFailure) {
        cout << cmd.getUsage();
    }
    return success ? 0 : -1;
}

OTVariable* Opentxs::setGlobalVar(OT_ME& madeEasy, const string& name,
                                  const string& value)
{
    if (value.size() == 0) {
        otInfo << "Variable " << name << " isn't set\n";
        return nullptr;
    }

    otWarn << "Variable " << name << " has value: " << value << "\n";

    OTVariable* var = new OTVariable(name, value, OTVariable::Var_Constant);
    OT_ASSERT(var != nullptr);
    madeEasy.AddVariable(name, *var);
    return var;
}
