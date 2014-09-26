/************************************************************
 *
 *  Basket.cpp
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

#include "opentxs/core/stdafx.hpp"

#include "Basket.hpp"

#include "opentxs/core/OTPseudonym.hpp"
#include "opentxs/core/OTLog.hpp"

#include <irrxml/irrXML.hpp>

// This is a good implementation. Dots all the i's, so to speak.
// client-side.
// The basket ONLY stores closing numbers, so this means "harvest 'em all."
//
// NOTE: The basket might be harvested in different ways, depending on context:
//
// 1. If the command-line client (OR ANY OTHER CLIENT) has a failure BEFORE
// sending the message,
//    (e.g. while constructing the basket exchange request), then it should call
// OTAPI.Msg_HarvestTransactionNumbers
//    and pass in the exchange basket string. That function will check to see if
// the input is an
//    exchange basket, and if so, it will load it up (AS A BASKET) into Basket
// and call the below
//    function to harvest the numbers.
//
// 2. If the high-level API actually SENDS the message, but the message FAILED
// before getting a chance
//    to process the exchangeBasket transaction, then the high-level API will
// pass the failed message
//    to OTAPI.Msg_HarvestTransactionNumbers, which will load it up (AS A
// MESSAGE) and that will then
//    call pMsg->HarvestTransactionNumbers, which then loads up the transaction
// itself in order to call
//    pTransaction->HarvestClosingNumbers. That function, if the transaction is
// indeed an exchangeBasket,
//    will then call the below function Basket::HarvestClosingNumbers.
//
// 3. If the high-level API sends the message, and it SUCCEEDS, but the
// exchangeBasket transaction inside
//    it has FAILED, then OTClient will harvest the transaction numbers when it
// receives the server reply
//    containing the failed transaction, by calling the below function,
// Basket::HarvestClosingNumbers.
//
// 4. If the basket exchange request is constructed successfully, and then the
// message processes at the server
//    successfully, and the transaction inside that message also processed
// successfully, then no harvesting will
//    be performed at all (obviously.)
//

namespace opentxs
{

void Basket::HarvestClosingNumbers(OTPseudonym& theNym,
                                   const OTIdentifier& theServerID, bool bSave)
{
    const OTString strServerID(theServerID);
    bool bNeedToSave = false;

    // The SUB-CURRENCIES first...
    //
    const uint32_t nCount = static_cast<uint32_t>(Count());

    for (uint32_t i = 0; i < nCount; i++) {
        BasketItem* pRequestItem = At(i);
        OT_ASSERT(nullptr != pRequestItem);

        const int64_t lClosingTransNo = pRequestItem->lClosingTransactionNo;

        // This function will only "add it back" if it was really there in the
        // first place.
        // (Verifies it is on issued list first, before adding to available
        // list.)
        //
        const bool bClawedBack = theNym.ClawbackTransactionNumber(
            theServerID, lClosingTransNo, false); // bSave=false

        if (bClawedBack) bNeedToSave = true;
    }
    // Then the BASKET currency itself...
    //
    const int64_t lClosingTransNo = GetClosingNum();

    // This function will only "add it back" if it was really there in the first
    // place.
    // (Verifies it is on issued list first, before adding to available list.)
    //
    const bool bClawedBack =
        theNym.ClawbackTransactionNumber(theServerID, lClosingTransNo, false);

    if (bClawedBack) bNeedToSave = true;

    // Until I put this down here, there were subtle cases where the Nym
    // wouldn't get saved.
    // Therefore another vote for my "dirty instances" theory.
    //
    if (bSave && bNeedToSave) {
        OTPseudonym* pSignerNym = &theNym; // probably unnecessary.
        theNym.SaveSignedNymfile(*pSignerNym);
    }
}

// For generating a user request to EXCHANGE in/out of a basket.
// Assumes that SetTransferMultiple has already been called.
void Basket::AddRequestSubContract(const OTIdentifier& SUB_CONTRACT_ID,
                                   const OTIdentifier& SUB_ACCOUNT_ID,
                                   const int64_t& lClosingTransactionNo)
{
    BasketItem* pItem = new BasketItem;

    OT_ASSERT_MSG(nullptr != pItem,
                  "Error allocating memory in Basket::AddRequestSubContract\n");

    // Minimum transfer amount is not set on a request. The server already knows
    // its value.
    // Also there is no multiple on the item, only on the basket as a whole.
    // ALL items are multiplied by the same multiple. Even the basket amount
    // itself is also.
    m_dequeItems.push_back(pItem);

    pItem->SUB_CONTRACT_ID = SUB_CONTRACT_ID;
    pItem->SUB_ACCOUNT_ID = SUB_ACCOUNT_ID;

    // When the basketReceipts are accepted in all the asset accounts,
    // each one will have a transaction number, lClosingTransactionNo,
    // which the user will finally clear from his record by accepting
    // from his inbox.
    pItem->lClosingTransactionNo = lClosingTransactionNo;
}

// For generating a real basket
void Basket::AddSubContract(const OTIdentifier& SUB_CONTRACT_ID,
                            int64_t lMinimumTransferAmount)
{
    BasketItem* pItem = new BasketItem;

    OT_ASSERT_MSG(nullptr != pItem,
                  "Error allocating memory in Basket::AddSubContract\n");

    pItem->SUB_CONTRACT_ID = SUB_CONTRACT_ID;
    pItem->lMinimumTransferAmount = lMinimumTransferAmount;

    m_dequeItems.push_back(pItem);
}

// The closing transaction number is the one that gets closed when the
// basketReceipt
// is accepted for the exchange that occured, specific to the basket item at
// nIndex.
// (Each asset account gets its own basketReceipt when an exchange happens.)
//
int64_t Basket::GetClosingTransactionNoAt(uint32_t nIndex)
{
    OT_ASSERT_MSG((nIndex < m_dequeItems.size()),
                  "Basket::GetClosingTransactionNoAt: index out of bounds.");

    BasketItem* pItem = m_dequeItems.at(nIndex);

    OT_ASSERT_MSG(nullptr != pItem, "Basket::GetClosingTransactionNoAt: basket "
                                    "item was nullptr at that index.");

    return pItem->lClosingTransactionNo;
}

BasketItem* Basket::At(uint32_t nIndex)
{
    if (nIndex < m_dequeItems.size()) return m_dequeItems.at(nIndex);

    return nullptr;
}

int32_t Basket::Count() const
{
    return static_cast<int32_t>(m_dequeItems.size());
}

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int32_t Basket::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
    const OTString strNodeName(xml->getNodeName());

    if (strNodeName.Compare("currencyBasket")) {
        OTString strSubCount, strMinTrans;
        strSubCount = xml->getAttributeValue("contractCount");
        strMinTrans = xml->getAttributeValue("minimumTransfer");

        m_nSubCount = atoi(strSubCount.Get());
        m_lMinimumTransfer = atol(strMinTrans.Get());

        otWarn << "Loading currency basket...\n";

        return 1;
    }
    else if (strNodeName.Compare("requestExchange")) {
        OTString strTransferMultiple, strRequestAccountID, strDirection,
            strTemp;

        strTransferMultiple = xml->getAttributeValue("transferMultiple");
        strRequestAccountID = xml->getAttributeValue("transferAccountID");
        strDirection = xml->getAttributeValue("direction");
        strTemp = xml->getAttributeValue("closingTransactionNo");

        if (strTransferMultiple.Exists())
            m_nTransferMultiple = atoi(strTransferMultiple.Get());
        if (strRequestAccountID.Exists())
            m_RequestAccountID.SetString(strRequestAccountID);
        if (strDirection.Exists()) m_bExchangingIn = strDirection.Compare("in");
        if (strTemp.Exists()) SetClosingNum(atol(strTemp.Get()));

        otInfo << "Basket Transfer multiple is " << m_nTransferMultiple
               << ". Direction is " << strDirection << ". Closing number is "
               << m_lClosingTransactionNo << ". Target account is:\n"
               << strRequestAccountID << "\n";

        return 1;
    }
    else if (strNodeName.Compare("basketItem")) {
        BasketItem* pItem = new BasketItem;

        OT_ASSERT_MSG(nullptr != pItem,
                      "Error allocating memory in Basket::ProcessXMLNode\n");

        OTString strTemp;

        strTemp = xml->getAttributeValue("minimumTransfer");
        if (strTemp.Exists())
            pItem->lMinimumTransferAmount = atol(strTemp.Get());

        strTemp = xml->getAttributeValue("closingTransactionNo");
        if (strTemp.Exists())
            pItem->lClosingTransactionNo = atol(strTemp.Get());

        OTString strSubAccountID(xml->getAttributeValue("accountID")),
            strContractID(xml->getAttributeValue("assetID"));
        pItem->SUB_ACCOUNT_ID.SetString(strSubAccountID);
        pItem->SUB_CONTRACT_ID.SetString(strContractID);

        m_dequeItems.push_back(pItem);

        otInfo << "Loaded basket item.\n";

        return 1;
    }

    return 0;
}

// Before transmission or serialization, this is where the basket updates its
// contents
void Basket::UpdateContents()
{
    GenerateContents(m_xmlUnsigned, m_bHideAccountID);
}

void Basket::GenerateContents(OTStringXML& xmlUnsigned,
                              bool bHideAccountID) const
{
    // I release this because I'm about to repopulate it.
    xmlUnsigned.Release();

    xmlUnsigned.Concatenate("<currencyBasket contractCount=\"%d\"\n"
                            " minimumTransfer=\"%lld\" >\n\n",
                            m_nSubCount, m_lMinimumTransfer);

    // Only uesd in Request Basket (requesting an exchange in/out.)
    // (Versus a basket object used for ISSUING a basket currency, this is
    // EXCHANGING instead.)
    //
    if (IsExchanging()) {
        OTString strRequestAcctID(m_RequestAccountID);
        xmlUnsigned.Concatenate("<requestExchange "
                                "transferMultiple=\"%d\"\n "
                                "transferAccountID=\"%s\"\n "
                                "closingTransactionNo=\"%lld\"\n "
                                "direction=\"%s\" />\n\n",
                                m_nTransferMultiple, strRequestAcctID.Get(),
                                m_lClosingTransactionNo,
                                m_bExchangingIn ? "in" : "out");
    }

    for (int32_t i = 0; i < Count(); i++) {
        BasketItem* pItem = m_dequeItems[i];

        OT_ASSERT_MSG(nullptr != pItem,
                      "Error allocating memory in Basket::UpdateContents\n");

        OTString strAcctID(pItem->SUB_ACCOUNT_ID),
            strContractID(pItem->SUB_CONTRACT_ID);

        if (IsExchanging())
            xmlUnsigned.Concatenate(
                "<basketItem minimumTransfer=\"%lld\"\n"
                " closingTransactionNo=\"%lld\"\n"
                " accountID=\"%s\"\n"
                " assetID=\"%s\" />\n\n",
                pItem->lMinimumTransferAmount, pItem->lClosingTransactionNo,
                bHideAccountID ? "" : strAcctID.Get(), strContractID.Get());
        else
            xmlUnsigned.Concatenate("<basketItem minimumTransfer=\"%lld\"\n"
                                    " accountID=\"%s\"\n"
                                    " assetID=\"%s\" />\n\n",
                                    pItem->lMinimumTransferAmount,
                                    bHideAccountID ? "" : strAcctID.Get(),
                                    strContractID.Get());
    }

    xmlUnsigned.Concatenate("</currencyBasket>\n");
}

// Most contracts calculate their ID by hashing the Raw File (signatures and
// all).
// The Basket only hashes the unsigned contents, and only with the account IDs
// removed.
// This way, the basket will produce a consistent ID across multiple different
// servers.
void Basket::CalculateContractID(OTIdentifier& newID) const
{
    // Produce a version of the file without account IDs (which are different
    // from server to server.)
    // do this on a copy since we don't want to modify this basket
    OTStringXML xmlUnsigned;
    GenerateContents(xmlUnsigned, true);

    newID.CalculateDigest(xmlUnsigned);
}

Basket::Basket(int32_t nCount, int64_t lMinimumTransferAmount)
    : OTContract()
    , m_nSubCount(nCount)
    , m_lMinimumTransfer(lMinimumTransferAmount)
    , m_nTransferMultiple(0)
    , m_bHideAccountID(false)
    , m_bExchangingIn(false)
    , m_lClosingTransactionNo(0)
{
}

Basket::Basket()
    : OTContract()
    , m_nSubCount(0)
    , m_lMinimumTransfer(0)
    , m_nTransferMultiple(0)
    , m_bHideAccountID(false)
    , m_bExchangingIn(false)
    , m_lClosingTransactionNo(0)
{
}

Basket::~Basket()
{
    Release_Basket();
}

void Basket::Release_Basket()
{
    m_RequestAccountID.Release();

    while (!m_dequeItems.empty()) {
        BasketItem* pItem = m_dequeItems.front();
        m_dequeItems.pop_front();
        delete pItem;
    }

    m_nSubCount = 0;
    m_lMinimumTransfer = 0;
    m_nTransferMultiple = 0;
    m_bHideAccountID = false;
    m_bExchangingIn = false;
    m_lClosingTransactionNo = 0;
}

void Basket::Release()
{
    Release_Basket();

    OTContract::Release();
}

bool Basket::SaveContractWallet(std::ofstream&) const
{
    return true;
}

} // namespace opentxs