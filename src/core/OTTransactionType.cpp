/************************************************************
 *
 *  OTTransactionType.cpp
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

#include <opentxs/core/stdafx.hpp>

#include <opentxs/core/OTTransactionType.hpp>

#include <opentxs/core/Account.hpp>
#include <opentxs/core/OTLedger.hpp>
#include <opentxs/core/OTLog.hpp>

// static -- class factory.
//

namespace opentxs
{

OTTransactionType* OTTransactionType::TransactionFactory(String strInput)
{
    String strContract, strFirstLine; // output for the below function.
    const bool bProcessed =
        Contract::DearmorAndTrim(strInput, strContract, strFirstLine);

    if (bProcessed) {
        OTTransactionType* pContract = nullptr;

        if (strFirstLine.Contains(
                "-----BEGIN SIGNED TRANSACTION-----")) // this string is 34
                                                       // chars long.
        {
            pContract = new OTTransaction();
            OT_ASSERT(nullptr != pContract);
        }
        else if (strFirstLine.Contains(
                       "-----BEGIN SIGNED TRANSACTION ITEM-----")) // this
                                                                   // string is
                                                                   // 39 chars
                                                                   // long.
        {
            pContract = new OTItem();
            OT_ASSERT(nullptr != pContract);
        }
        else if (strFirstLine.Contains(
                       "-----BEGIN SIGNED LEDGER-----")) // this string is 29
                                                         // chars long.
        {
            pContract = new OTLedger();
            OT_ASSERT(nullptr != pContract);
        }
        else if (strFirstLine.Contains(
                       "-----BEGIN SIGNED ACCOUNT-----")) // this string is 30
                                                          // chars long.
        {
            pContract = new Account();
            OT_ASSERT(nullptr != pContract);
        }

        // The string didn't match any of the options in the factory.
        //

        const char* szFunc = "OTTransactionType::TransactionFactory";
        // The string didn't match any of the options in the factory.
        if (nullptr == pContract) {
            otOut << szFunc
                  << ": Object type not yet supported by class factory: "
                  << strFirstLine << "\n";
            return nullptr;
        }

        // This causes pItem to load ASSUMING that the PurportedAcctID and
        // PurportedNotaryID are correct.
        // The object is still expected to be internally consistent with its
        // sub-items, regarding those IDs,
        // but the big difference is that it will SET the Real Acct and Real
        // Notary IDs based on the purported
        // values. This way you can load a transaction without knowing the
        // account in advance.
        //
        pContract->SetLoadInsecure();

        // Does the contract successfully load from the string passed in?
        if (pContract->LoadContractFromString(strContract)) {
            // NOTE: this already happens in OTTransaction::ProcessXMLNode and
            // OTLedger::ProcessXMLNode.
            // Specifically, it happens when m_bLoadSecurely is set to false.
            //
            //          pContract->SetRealNotaryID(pItem->GetPurportedNotaryID());
            //          pContract->SetRealAccountID(pItem->GetPurportedAccountID());
            //
            return pContract;
        }
        else {
            otOut << szFunc
                  << ": Failed loading contract from string (first line): "
                  << strFirstLine << "\n";
            delete pContract;
            pContract = nullptr;
        }
    }

    return nullptr;
}

void OTTransactionType::GetNumList(OTNumList& theOutput)
{
    theOutput.Release();
    theOutput.Add(m_Numlist);
}

// Allows you to string-search the raw contract.
bool OTTransactionType::Contains(const String& strContains)
{
    return m_strRawFile.Contains(strContains);
}

// Allows you to string-search the raw contract.
bool OTTransactionType::Contains(const char* szContains)
{
    return m_strRawFile.Contains(szContains);
}

// keeping constructor private in order to force people to use the other
// constructors and
// therefore provide the requisite IDs.
OTTransactionType::OTTransactionType()
    : Contract()
    , m_lTransactionNum(0)
    , m_lInReferenceToTransaction(0)
    , m_lNumberOfOrigin(0)
    , m_bLoadSecurely(true)
{
    // this function is private to prevent people from using it.
    // Should never actually get called.

    //    InitTransactionType(); // Just in case.
}

OTTransactionType::OTTransactionType(const Identifier& theNymID,
                                     const Identifier& theAccountID,
                                     const Identifier& theNotaryID)
    : Contract(theAccountID)
    , m_NotaryID(theNotaryID)
    , m_AcctNymID(theNymID)
    , m_lTransactionNum(0)
    , m_lInReferenceToTransaction(0)
    , m_lNumberOfOrigin(0)
    , m_bLoadSecurely(true)
{
    //    InitTransactionType();

    //  m_ID            = theAccountID  -- This happens in OTContract, no need
    // to do it twice.

    // do NOT set m_AcctID and m_AcctNotaryID here.  Let the child classes LOAD
    // them or GENERATE them.
}

OTTransactionType::OTTransactionType(const Identifier& theNymID,
                                     const Identifier& theAccountID,
                                     const Identifier& theNotaryID,
                                     int64_t lTransactionNum)
    : Contract(theAccountID)
    , m_NotaryID(theNotaryID)
    , m_AcctNymID(theNymID)
    , m_lTransactionNum(lTransactionNum)
    , m_lInReferenceToTransaction(0)
    , m_lNumberOfOrigin(0)
    , m_bLoadSecurely(true)
{
    // This initializes m_lTransactionNum, so it must come FIRST.
    // In fact, that's the general rule with this function.
    //    InitTransactionType();

    //  m_ID                = theAccountID  -- This happens in OTContract, no
    // need to do it twice.

    // do NOT set m_AcctID and m_AcctNotaryID here.  Let the child classes LOAD
    // them or GENERATE them.
}

// Note: can probably remove this function entirely...
void OTTransactionType::InitTransactionType()
{
    m_lTransactionNum = 0;
    m_lInReferenceToTransaction = 0;
    m_lNumberOfOrigin = 0;
}

OTTransactionType::~OTTransactionType()
{
    Release_TransactionType();
}

// We'll see if any new bugs pop up after adding this...
//
void OTTransactionType::Release_TransactionType()
{
    // If there were any dynamically allocated objects, clean them up here.

    //  m_ID.Release();
    m_AcctID.Release(); // Compare m_AcctID to m_ID after loading it from string
                        // or file. They should match, and signature should
                        // verify.

    //    m_NotaryID.Release();       // Notary ID as used to instantiate the
    // transaction, based on expected NotaryID.
    m_AcctNotaryID.Release(); // Actual NotaryID within the signed portion.
                              // (Compare to m_NotaryID upon loading.)

    //    m_AcctNymID.Release();

    m_lTransactionNum = 0;
    m_lInReferenceToTransaction = 0;
    m_lNumberOfOrigin = 0;

    m_ascInReferenceTo.Release(); // This item may be in reference to a
                                  // different item

    // This was causing OTLedger to fail loading. Can't set this to true until
    // the END
    // of loading. Todo: Starting reading the END TAGS during load. For example,
    // the OTLedger
    // END TAG could set this back to true...
    //
    //  m_bLoadSecurely = true; // defaults to true.

    m_Numlist.Release();
}

void OTTransactionType::Release()
{
    Release_TransactionType();

    Contract::Release(); // since I've overridden the base class, I call it
                         // now...
}

// OTAccount, OTTransaction, OTItem, and OTLedger are all derived from
// this class (OTTransactionType). Therefore they can all quickly identify
// whether one of the other components belongs to the same account, using
// this method.
//
bool OTTransactionType::IsSameAccount(const OTTransactionType& rhs) const
{
    if ((GetNymID() != rhs.GetNymID()) ||
        (GetRealAccountID() != rhs.GetRealAccountID()) ||
        (GetRealNotaryID() != rhs.GetRealNotaryID()))
        return false;
    return true;
}

void OTTransactionType::GetReferenceString(String& theStr) const
{
    m_ascInReferenceTo.GetString(theStr);
}

void OTTransactionType::SetReferenceString(const String& theStr)
{
    m_ascInReferenceTo.SetString(theStr);
}

// Make sure this contract checks out. Very high level.
// Verifies ID and signature.
// I do NOT call VerifyOwner() here, because the server may
// wish to verify its signature on this account, even though
// the server may not be the actual owner.
// So if you wish to VerifyOwner(), then call it.
bool OTTransactionType::VerifyAccount(const Nym& theNym)
{
    // Make sure that the supposed AcctID matches the one read from the file.
    //
    if (!VerifyContractID()) {
        otErr << "Error verifying account ID in "
                 "OTTransactionType::VerifyAccount\n";
        return false;
    }
    else if (!VerifySignature(theNym)) {
        otErr << "Error verifying signature in "
                 "OTTransactionType::VerifyAccount.\n";
        return false;
    }

    otLog4 << "\nWe now know that...\n"
              "1) The expected Account ID matches the ID that was found on the "
              "object.\n"
              "2) The SIGNATURE VERIFIED on the object.\n\n";
    return true;
}

bool OTTransactionType::VerifyContractID() const
{
    // m_AcctID contains the number we read from the xml file
    // we can compare it to the existing and actual identifier.

    // m_AcctID  contains the "IDENTIFIER" of the object, according to the xml
    // file.
    //
    // Meanwhile m_ID contains the same identifier, except it was generated.
    //
    // Now let's compare the two and make sure they match...

    // Also, for this class, we compare NotaryID as well.  They go hand in hand.

    if ((m_ID != m_AcctID) || (m_NotaryID != m_AcctNotaryID)) {
        String str1(m_ID), str2(m_AcctID), str3(m_NotaryID),
            str4(m_AcctNotaryID);
        otErr << "Identifiers do NOT match in "
                 "OTTransactionType::VerifyContractID.\n"
                 "m_ID: " << str1 << "\n m_AcctID: " << str2
              << "\n m_NotaryID: " << str3 << "\n m_AcctNotaryID: " << str4
              << "\n";

        //        OT_FAIL;  // I was debugging.

        return false;
    }
    else {
        //        OTString str1(m_AcctID), str2(m_AcctNotaryID);
        //        otErr << "Expected Account ID and Notary ID both *SUCCESSFUL*
        // match to "
        //                "IDs in the xml:\n Account ID:\n%s\n NotaryID:\n%s\n"
        //                "-----------------------------------------------------------------------------\n",
        //                str1.Get(), str2.Get());
        return true;
    }
}

// Need to know the transaction number of this transaction? Call this.
int64_t OTTransactionType::GetTransactionNum() const
{
    return m_lTransactionNum;
}

void OTTransactionType::SetTransactionNum(int64_t lTransactionNum)
{
    m_lTransactionNum = lTransactionNum;
}

// virtual
void OTTransactionType::CalculateNumberOfOrigin()
{
    m_lNumberOfOrigin = m_lTransactionNum;
}

// Need to know the transaction number of the ORIGINAL transaction? Call this.
// virtual
int64_t OTTransactionType::GetNumberOfOrigin()
{
    if (0 == m_lNumberOfOrigin) CalculateNumberOfOrigin();

    return m_lNumberOfOrigin;
}

// Gets WITHOUT calculating.
int64_t OTTransactionType::GetRawNumberOfOrigin() const
{
    return m_lNumberOfOrigin;
}

void OTTransactionType::SetNumberOfOrigin(int64_t lTransactionNum)
{
    m_lNumberOfOrigin = lTransactionNum;
}

void OTTransactionType::SetNumberOfOrigin(OTTransactionType& setFrom)
{
    m_lNumberOfOrigin = setFrom.GetNumberOfOrigin();
}

// Allows you to compare any OTTransaction or OTItem to any other OTTransaction
// or OTItem,
// and see if they share the same origin number.
//
// Let's say Alice sends a transfer #100 to Bob.
// Then Bob receives a pending in his inbox, #800, which is in reference to
// #100.
// Then Bob accepts the pending with processInbox #45, which is in reference to
// #800.
// Then Alice receives a transferReceipt #64, which is in reference to #45.
// Then Alice accepts the transferReceipt with processInbox #91, in reference to
// #64.
//
// ALL OF THOSE transactions and receipts will have origin #100 attached to
// them.
//
bool OTTransactionType::VerifyNumberOfOrigin(OTTransactionType& compareTo)
{
    // Have to use the function here, NOT the internal variable.
    // (Because subclasses may override the function.)
    //
    return (GetNumberOfOrigin() == compareTo.GetNumberOfOrigin());
}

// Need to know the transaction number that this is in reference to? Call this.
int64_t OTTransactionType::GetReferenceToNum() const
{
    return m_lInReferenceToTransaction;
}

void OTTransactionType::SetReferenceToNum(int64_t lTransactionNum)
{
    m_lInReferenceToTransaction = lTransactionNum;
}

} // namespace opentxs
