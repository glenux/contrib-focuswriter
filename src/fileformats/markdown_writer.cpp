/***********************************************************************
 *
 * Copyright (C) 2013, 2014 Graeme Gott <graeme@gottcode.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#include "markdown_writer.h"

#include <QBuffer>
#include <QTextBlock>
#include <QTextBlockFormat>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QtZipWriter>

//-----------------------------------------------------------------------------

MarkdownWriter::MarkdownWriter(const QByteArray& encoding) :
	m_encoding(encoding),
	m_codec(0),
	m_supports_ascii(false)
{
	// FIXME: do something usefull
}

//-----------------------------------------------------------------------------

void MarkdownWriter::setStrict(bool strict)
{
	m_strict = strict;
}

//-----------------------------------------------------------------------------

bool MarkdownWriter::write(QIODevice* device, QTextDocument* document)
{
	return true;
}

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
