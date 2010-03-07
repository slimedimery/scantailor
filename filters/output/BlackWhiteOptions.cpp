/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C)  Joseph Artsimovich <joseph.artsimovich@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "BlackWhiteOptions.h"
#include <QDomDocument>
#include <QDomElement>
#include <QString>

namespace output
{

BlackWhiteOptions::BlackWhiteOptions()
:	m_thresholdAdjustment(0),
	m_dewarp(false)
{
}

BlackWhiteOptions::BlackWhiteOptions(QDomElement const& el)
:	m_thresholdAdjustment(el.attribute("thresholdAdj").toInt()),
	m_dewarp(el.attribute("dewarp") == "1")
{
}

QDomElement
BlackWhiteOptions::toXml(QDomDocument& doc, QString const& name) const
{
	QDomElement el(doc.createElement(name));
	el.setAttribute("thresholdAdj", m_thresholdAdjustment);
	el.setAttribute("dewarp", m_dewarp ? "1" : "0");
	return el;
}

bool
BlackWhiteOptions::operator==(BlackWhiteOptions const& other) const
{
	if (m_thresholdAdjustment != other.m_thresholdAdjustment) {
		return false;
	}
	
	if (m_dewarp != other.m_dewarp) {
		return false;
	}
	
	return true;
}

bool
BlackWhiteOptions::operator!=(BlackWhiteOptions const& other) const
{
	return !(*this == other);
}

} // namespace output
