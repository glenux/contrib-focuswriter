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

#include "format_manager.h"

#include "markdown_reader.h"
#include "docx_reader.h"
#include "odt_reader.h"
#include "rtf_reader.h"
#include "txt_reader.h"

#include <QStringList>

//-----------------------------------------------------------------------------

FormatReader* FormatManager::createReader(QIODevice* device, const QString& type)
{
	FormatReader* reader = 0;

	// Try file extension first
	if (type == "odt") {
		if (OdtReader::canRead(device)) {
			reader = new OdtReader;
		}
	} else if (type == "docx") {
		if (DocxReader::canRead(device)) {
			reader = new DocxReader;
		}
	} else if (type == "rtf") {
		if (RtfReader::canRead(device)) {
			reader = new RtfReader;
		}
	} else if (type == "md") {
		if (MarkdownReader::canRead(device)) {
			reader = new MarkdownReader;
		}
	}

	// Fall back to finding format from contents
	if (!reader) {
		if (OdtReader::canRead(device)) {
			reader = new OdtReader;
		} else if (DocxReader::canRead(device)) {
			reader = new DocxReader;
		} else if (RtfReader::canRead(device)) {
			reader = new RtfReader;
		} else {
			reader = new TxtReader;
		}
	}

	return reader;
}

//-----------------------------------------------------------------------------

QString FormatManager::filter(const QString& type)
{
	if (type == "odt") {
		return tr("OpenDocument Text") + QLatin1String(" (*.odt)");
	} else if (type == "docx") {
		return tr("Office Open XML") + QLatin1String(" (*.docx)");
	} else if (type == "rtf") {
		return tr("Rich Text Format") + QLatin1String(" (*.rtf)");
	} else if ((type == "txt") || (type == "text")) {
		return tr("Plain Text") + QLatin1String(" (*.txt *.text)");
	} else if ((type == "md") || (type == "markdown")) {
		return tr("Markdown") + QLatin1String(" (*.md *.markdown)");
	} else {
		return QString();
	}
}

//-----------------------------------------------------------------------------

QStringList FormatManager::filters(const QString& type)
{
	static const QStringList default_filters = QStringList()
			<< filter("odt")
			<< filter("docx")
			<< filter("rtf")
			<< filter("txt")
			<< filter("md")
			<< (tr("All Files") + QLatin1String(" (*)"));

	QStringList result = default_filters;
	if (!type.isEmpty()) {
		if (type == "docx") {
			result.move(1, 0);
		} else if (type == "rtf") {
			result.move(2, 0);
		} else if ((type == "txt") || (type == "text")) {
			result.move(3, 0);
		} else if (type != "odt") {
			result.move(4, 0);
		} else if ((type == "md") || (type == "markdown")) {
			result.move(5, 0);
		}

	} else {
		result.prepend(tr("All Supported Files") + QLatin1String(" (*.docx *.odt *.rtf *.txt *.text *.md *.markdown)"));
	}
	return result;
}

//-----------------------------------------------------------------------------

bool FormatManager::isRichText(const QString& filename)
{
	QString type = filename.section(QLatin1Char('.'), -1).toLower();
	return (type == "odt") || (type == "docx") || (type == "rtf") || (type == "md");
}

//-----------------------------------------------------------------------------

QStringList FormatManager::types()
{
	return QStringList() << "odt" << "docx" << "rtf" << "txt" << "md";
}

//-----------------------------------------------------------------------------
