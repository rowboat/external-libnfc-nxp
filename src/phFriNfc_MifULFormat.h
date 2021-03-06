/*
 * Copyright (C) 2010 NXP Semiconductors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * \file  phFriNfc_MifULFormat.h
 * \brief NFC Ndef Formatting For Mifare standard card.
 *
 * Project: NFC-FRI
 *
 * $Date: Wed Jun  3 14:38:25 2009 $
 * $Author: ing07336 $
 * $Revision: 1.4 $
 * $Aliases: NFC_FRI1.1_WK924_PREP1,NFC_FRI1.1_WK924_R27_1,NFC_FRI1.1_WK926_R28_1,NFC_FRI1.1_WK928_R29_1,NFC_FRI1.1_WK930_R30_1,NFC_FRI1.1_WK934_PREP_1,NFC_FRI1.1_WK934_R31_1,NFC_FRI1.1_WK941_PREP1,NFC_FRI1.1_WK941_PREP2,NFC_FRI1.1_WK941_1,NFC_FRI1.1_WK943_R32_1,NFC_FRI1.1_WK949_PREP1,NFC_FRI1.1_WK943_R32_10,NFC_FRI1.1_WK943_R32_13,NFC_FRI1.1_WK943_R32_14,NFC_FRI1.1_WK1007_R33_1,NFC_FRI1.1_WK1007_R33_4,NFC_FRI1.1_WK1017_PREP1,NFC_FRI1.1_WK1017_R34_1,NFC_FRI1.1_WK1017_R34_2,NFC_FRI1.1_WK1023_R35_1 $
 *
 */

#ifndef PHFRINFC_MIFULFORMAT_H
#define PHFRINFC_MIFULFORMAT_H

#include <phFriNfc.h>
#ifdef PH_HAL4_ENABLE
    #include <phHal4Nfc.h>
#else
    #include <phHalNfc.h>
#endif
#include <phNfcStatus.h>
#include <phNfcTypes.h>
#include <phFriNfc_SmtCrdFmt.h>

#ifdef PH_NDEF_MIFARE_ULC
#include <phFriNfc_NdefMap.h>
#endif /* #ifdef PH_NDEF_MIFARE_ULC */

#define PH_FRINFC_MIFUL_FORMAT_FILEREVISION "$Revision: 1.4 $"
#define PH_FRINFC_MIFUL_FORMAT_FILEALIASES  "$Aliases: NFC_FRI1.1_WK924_PREP1,NFC_FRI1.1_WK924_R27_1,NFC_FRI1.1_WK926_R28_1,NFC_FRI1.1_WK928_R29_1,NFC_FRI1.1_WK930_R30_1,NFC_FRI1.1_WK934_PREP_1,NFC_FRI1.1_WK934_R31_1,NFC_FRI1.1_WK941_PREP1,NFC_FRI1.1_WK941_PREP2,NFC_FRI1.1_WK941_1,NFC_FRI1.1_WK943_R32_1,NFC_FRI1.1_WK949_PREP1,NFC_FRI1.1_WK943_R32_10,NFC_FRI1.1_WK943_R32_13,NFC_FRI1.1_WK943_R32_14,NFC_FRI1.1_WK1007_R33_1,NFC_FRI1.1_WK1007_R33_4,NFC_FRI1.1_WK1017_PREP1,NFC_FRI1.1_WK1017_R34_1,NFC_FRI1.1_WK1017_R34_2,NFC_FRI1.1_WK1023_R35_1 $"


/*!
 * \name Mifare UL - constants for the state
 *
 */
/*@{*/
#define PH_FRINFC_MFUL_FMT_RESET_INIT          0 /*!< Reset state */
#define PH_FRINFC_MFUL_FMT_RD_16BYTES          1 /*!< Read 16 bytes */
#define PH_FRINFC_MFUL_FMT_WR_OTPBYTES         2 /*!< Write OTP bytes */
#define PH_FRINFC_MFUL_FMT_WR_TLV              3 /*!< Write TLV */  
#ifdef PH_NDEF_MIFARE_ULC
#define PH_FRINFC_MFUL_FMT_WR_TLV1             4 /*!< Write TLV (second part) */ 
#endif	/* #ifdef PH_NDEF_MIFARE_ULC */

/*@}*/


/*!
* \name Mifare standard - Block numbers
*
*/
/*@{*/
#define PH_FRINFC_MFUL_FMT_LOCK_BITS_VAL       0x00   /*!< Lock bits block is 2 */

/*@}*/

/*!
 * \name Mifare UL - OTP bytes
 *
 */
/*@{*/
#ifdef PH_NDEF_MIFARE_ULC
#define PH_FRINFC_MFULC_FMT_OTP_BYTES           {0xE1, 0x10, 0x12, 0x00}   /*!< OTP bytes macro */
#endif /* #ifdef PH_NDEF_MIFARE_ULC */
#define PH_FRINFC_MFUL_FMT_OTP_BYTES           {0xE1, 0x10, 0x06, 0x00}   /*!< OTP bytes macro */

/*@}*/

/*!
 * \name Mifare UL - enums the values 
 *
 */
/*@{*/
enum{
PH_FRINFC_MFUL_FMT_VAL_0, 
PH_FRINFC_MFUL_FMT_VAL_1,
PH_FRINFC_MFUL_FMT_VAL_2,
PH_FRINFC_MFUL_FMT_VAL_3,
PH_FRINFC_MFUL_FMT_VAL_4,
PH_FRINFC_MFUL_FMT_VAL_5,
PH_FRINFC_MFUL_FMT_VAL_6,
PH_FRINFC_MFUL_FMT_VAL_7
};
/*@}*/

/*!
 * \name Mifare UL - constants
 *
 */
/*@{*/
#define PH_FRINFC_MFUL_FMT_NON_NDEF_COMPL  0   /*!< Card is not ndef compliant */
#define PH_FRINFC_MFUL_FMT_NDEF_COMPL      1   /*!< Card is ndef compliant */
/*@}*/

/*!
 * \name Mifare UL - constants
 *
 */
/*@{*/
#define PH_FRINFC_MFUL_FMT_MAX_RECV_LENGTH      252 /*!< Maximum receive length */
#define PH_FRINFC_MFUL_FMT_WR_SEND_LENGTH       5  /*!< Send length for write */
#define PH_FRINFC_MFUL_FMT_MAX_BLK              16  /*!< Maximum blocks */

/*@}*/

/*!
 * \name Mifare UL - constants for filling send buffer, calculating the block number,
 * checking the authenticate state
 *
 */
/*@{*/

/*@}*/


/**
 * \ingroup grp_fri_smart_card_formatting
 * \brief Smart Card Formatting \b Reset function
 *
 * \copydoc page_reg Resets the component instance to the initial state and initializes the 
 *          internal variables.
 */
void phFriNfc_MfUL_Reset(phFriNfc_sNdefSmtCrdFmt_t    *NdefSmtCrdFmt);

/*!
 * \ingroup grp_fri_smart_card_formatting
 *
 * \brief Initiates the card formatting procedure for Remote Smart Card Type.
 *
 * \copydoc page_ovr  The function initiates and formats the Smart Card.After this formation, remote
 * card would be properly initialized and Ndef Compliant.
 * Depending upon the different card type, this function handles formatting procedure.
 * This function also handles the different recovery procedures for different types of the cards. For both
 * Format and Recovery Management same API is used.
 * 
 * \param[in] phFriNfc_sNdefSmartCardFmt_t Pointer to a valid instance of the \ref phFriNfc_sNdefSmartCardFmt_t
 *                             structure describing the component context.
 * \retval  NFCSTATUS_PENDING   The action has been successfully triggered.
 * \retval  Other values        An error has occurred.
 *
 */
NFCSTATUS phFriNfc_MfUL_Format(phFriNfc_sNdefSmtCrdFmt_t    *NdefSmtCrdFmt);

/**
 *\ingroup grp_fri_smart_card_formatting
 *
 * \brief Smart card Formatting \b Completion \b Routine or \b Process function
 *
 * \copydoc page_ovr Completion Routine: This function is called by the lower layer (OVR HAL)
 *                  when an I/O operation has finished. The internal state machine decides
 *                  whether to call into the lower device again or to complete the process
 *                  by calling into the upper layer's completion routine, stored within this
 *                  component's context (\ref phFriNfc_sNdefSmtCrdFmt_t).
 *
 * The function call scheme is according to \ref grp_interact. No State reset is performed during
 * operation.
 *
 * \param[in] Context The context of the current (not the lower/upper) instance, as set by the lower,
 *            calling layer, upon its completion.
 * \param[in] Status  The completion status of the lower layer (to be handled by the implementation of
 *                    the state machine of this function like a regular return value of an internally
 *                    called function).
 *
 * \note For general information about the completion routine interface please see \ref pphFriNfc_Cr_t . * The Different Status Values are as follows
 *
 */
void phFriNfc_MfUL_Process(void            *Context,
                            NFCSTATUS       Status);
#endif /* PHFRINFC_MIFULFORMAT_H */

