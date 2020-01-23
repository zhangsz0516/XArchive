// copyright (c) 2017-2020 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef SEVENZIP_H
#define SEVENZIP_H

#include <QObject>
#include "xarchive.h"

class SevenZip : public XArchive
{
    Q_OBJECT

public:    
#pragma pack(push)
#pragma pack(1)
    struct SignatureHeader
    {
        quint8 kSignature[6]; // {'7','z',0xBC,0xAF,0x27,0x1C}
        quint8 Major;   // now = 0
        quint8 Minor;   // now = 4
        quint32 StartHeaderCRC;
        quint64 NextHeaderOffset;
        quint64 NextHeaderSize;
        quint32 NextHeaderCRC;
    };
#pragma pack(pop)

    explicit SevenZip(QIODevice *__pDevice=0);
    virtual bool isValid();
    virtual QString getVersion();
    virtual quint64 getNumberOfRecords();
    virtual QList<RECORD> getRecords(qint32 nLimit=-1);

private:
};

#endif // SEVENZIP_H
