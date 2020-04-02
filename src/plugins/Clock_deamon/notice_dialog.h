#ifndef NOTICE_DIALOG_H
#define NOTICE_DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

namespace Ui {
class Notice_Dialog;
}

class Notice_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Notice_Dialog(QWidget *parent = nullptr, int close_time = 0,int alarm_num= 0);
    ~Notice_Dialog();

    Ui::Notice_Dialog *ui;
    void setupUi(QDialog *Notice_Dialog);
    void retranslateUi(QDialog *Notice_Dialog);

    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;

private slots:
    void set_dialog_close();
    void close_music();

private:
    QTimer *timer = nullptr;
    int timer_value;
    QMediaPlayer  *music;

};

#endif // NOTICE_DIALOG_H
