/***********************************************************************
 *
 * Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
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

#ifndef MARKDOWN_WRITER_H
#define MARKDOWN_WRITER_H

#include <QCoreApplication>
#include <QString>
#include <QXmlStreamWriter>
class QIODevice;
class QTextBlock;
class QTextBlockFormat;
class QTextCharFormat;
class QTextDocument;

class MarkdownWriter
{
	Q_DECLARE_TR_FUNCTIONS(MarkdownWriter)

public:
	MarkdownWriter();

	QString errorString() const
	{
		return m_error;
	}

	void setStrict(bool strict);
	bool write(const QString& filename, QTextDocument* document);

private:
	// functions declaration here

private:
	QXmlStreamWriter m_xml;
	bool m_strict;
	QString m_error;
};

#endif
