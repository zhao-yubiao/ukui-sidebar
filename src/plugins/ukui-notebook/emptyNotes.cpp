/*
* Copyright (C) 2020 Tianjin KYLIN Information Technology Co., Ltd.
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

#include <QBitmap>
#include <QDebug>
#include <QPainter>
#include <QPainterPath>

#include "emptyNotes.h"
#include "ui_emptyNotes.h"
#include "utils/xatom-helper.h"

emptyNotes::emptyNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emptyNotes)
{
    ui->setupUi(this);
    setWindowTitle(tr("emptyNotes"));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);

    // 添加窗管协议
    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(this->winId(), hints);

//    ui->widget->setStyleSheet("QWidget{background-color: rgba(255, 255, 255, 0.4);}");
//    ui->label->setStyleSheet("background-color: rgba();\
//                             font-size:20px;\
//                                font-weight:400;\
//                                color:rgba(40,40,40,1);\
//                                line-height:34px;\
//                                opacity:0.97;\
//                                 ");
//    ui->checkBox->setStyleSheet("background-color: rgba();\
//                                font-size:14px;\
//                                font-weight:400;\
//                                color:rgba(102,102,102,1);\
//                                line-height:40px;\
//                                opacity:0.91;");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()) );
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()) );
}

void emptyNotes::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
    QPainterPath rectPath;
    rectPath.addRect(this->rect());
    p.fillPath(rectPath,palette().color(QPalette::Base));
}

emptyNotes::~emptyNotes()
{
    delete ui;
}

void emptyNotes::on_pushButton_clicked()
{
    this->close();
}

void emptyNotes::on_pushButton_2_clicked()
{
    emit requestEmptyNotes();
    this->close();
}
