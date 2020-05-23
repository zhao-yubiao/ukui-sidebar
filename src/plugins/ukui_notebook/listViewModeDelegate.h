/*
* Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/
#ifndef LISTVIEWMODEDELEGATE_H
#define LISTVIEWMODEDELEGATE_H

#include <QStyledItemDelegate>
#include <QTimeLine>

class listViewModeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    listViewModeDelegate(QObject *parent = Q_NULLPTR);

    enum States{
        Normal,
        Insert,
        Remove,
        MoveOut,
        MoveIn
    };


    void setState(States NewState , QModelIndex index);
    void setAnimationDuration(const int duration);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;

    QTimeLine::State animationState();

    void setCurrentSelectedIndex(const QModelIndex &currentSelectedIndex);
    void setHoveredIndex(const QModelIndex &hoveredIndex);
    void setRowRightOffset(int rowRightOffset);
    void setActive(bool isActive);
    int qcolorToInt(const QColor &color) const;
    QColor intToQcolor(int &intColor) const;

private:
    void paintBackground(QPainter* painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
    void paintLabels(QPainter* painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paintSeparator(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QString parseDateTime(const QDateTime& dateTime) const;

    QFont m_titleFont;
    QFont m_titleSelectedFont;
    QFont m_dateFont;
    QColor m_titleColor;
    QColor m_dateColor;
    QColor m_ActiveColor;
    QColor m_notActiveColor;
    QColor m_hoverColor;
    QColor m_selectColor;
    QColor m_applicationInactiveColor;
    QColor m_separatorColor;
    QColor m_defaultColor;
    QColor m_noteColor;
    int m_rowHeight;
    int m_maxFrame;
    int m_rowRightOffset;
    States m_state;
    bool m_isActive;

    QTimeLine *m_timeLine;
    QModelIndex m_animatedIndex;
    QModelIndex m_currentSelectedIndex;
    QModelIndex m_hoveredIndex;

signals:
    void update(const QModelIndex &index);
};

#endif // LISTVIEWMODEDELEGATE_H