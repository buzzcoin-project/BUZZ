BuzzCoin v2.1.1.0

Copyright (c) 2013 NovaCoin Developers
Copyright (c) 2011-2012 PPCoin Developers
Copyright (c) 2017 BUZZ Developers
Distributed under the MIT/X11 software license, see the accompanying
file license.txt or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).  This product includes
cryptographic software written by Eric Young (eay@cryptsoft.com).


# Intro

BuzzCoin is a free open source project derived from Bitcoin, with
the goal of providing a long-term energy-efficient scrypt-based crypto-currency.

Built on the foundation of Bitcoin, PPCoin and NovaCoin, innovations such as proof-of-stake
help further advance the field of crypto-currency.

# TODO LIST

## V3 Coin Minting Stability

if block divisible by 1200, APR = 1200

APR = 1200 - 1200 * (CURRENT_COIN_SUPPLY / MAX_COIN_SUPPLY)

&&

if block divislble by 1200, MATURATION = instant

MATURATION = CURRENT_SUPPLY (rounded down to nearest billion and strip all 0s)
 
## Automated Fund to Development wallet.

- [] create qt settings input field with checkbox -> bDonationCheckbox
- [] allow minimum input of 2.5% of stake -> dPercentageDonation
- [] enable larger inputs for dPercentageDonation
- [] when stake is received, send automatic donation to sDevWalletAddress