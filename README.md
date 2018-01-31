BuzzCoin v3.0.1

Copyright (c) 2013 NovaCoin Developers Copyright (c) 2011-2012 PPCoin Developers
Copyright (c) 2017 BUZZ Developers Distributed under the MIT/X11 software
license, see the accompanying file license.txt or
http://www.opensource.org/licenses/mit-license.php. This product includes
software developed by the OpenSSL Project for use in the OpenSSL Toolkit
(http://www.openssl.org/). This product includes cryptographic software written
by Eric Young (eay@cryptsoft.com).

# Intro

BuzzCoin is a free open source project derived from Bitcoin, with the goal of
providing a long-term energy-efficient scrypt-based crypto-currency.

Built on the foundation of Bitcoin, PPCoin and NovaCoin, innovations such as
proof-of-stake help further advance the field of crypto-currency.

# Development

## testnet

if anyone wants to get a testnet node up and running

add this to buzzcoin.conf

```
# testnet
addnode=188.165.59.82:20114
addnode=51.15.198.252:20114
addnode=45.77.101.51:20114
addnode=188.165.59.82
addnode=51.15.198.252
addnode=45.77.101.51

rpcuser=YOUR_USER
rpcpassword=YOUR_PASS
rpcallowip=127.0.0.1
listen=1
```

download minerd to do PoW mining (helps lube chain)
https://bitcointalk.org/index.php?topic=55038.0
use

```
./minerd -a sha256d -o http://127.0.0.1:20115/ -O YOUR_USER:YOUR_PASS -t 1
```

to mine.

share your addresses so people can test development rewards. send BUZZ to them so they can stake too

## Useful debugging command utilities

### OS X

```
./BuzzCoin-Qt.App/Contents/MacOS/BuzzCoin-Qt --debug # debug
cd ~/Library/Application Support/BuzzCoin && tail -f debug.log # live debug output
/usr/local/opt/qt/bin/qmake -o Makefile buzzcoin.pro RELEASE=1 USE_QRCODE=1 # proper qmake using pro
```
