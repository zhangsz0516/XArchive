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
#include "sevenzip.h"

SevenZip::SevenZip(QIODevice *__pDevice) : XArchive(__pDevice)
{

}

bool SevenZip::isValid()
{
    bool bResult=false;

    if(getSize()>sizeof(SignatureHeader))
    {
        if(compareSignature("'7z'BCAF271C"))
        {
            bResult=true;
        }
    }

    return bResult;
}

QString SevenZip::getVersion()
{
    return QString("%1.%2").arg(read_uint8(6)).arg(read_uint8(7),1,10,QChar('0'));
}

quint64 SevenZip::getNumberOfRecords()
{
    SignatureHeader signatureHeader;

    if(read_array(0,(char *)&signatureHeader,sizeof(SignatureHeader))==sizeof(SignatureHeader))
    {

    }

    return 0;
}

QList<XArchive::RECORD> SevenZip::getRecords(qint32 nLimit)
{
    QList<XArchive::RECORD> listResult;

    return listResult;
}
