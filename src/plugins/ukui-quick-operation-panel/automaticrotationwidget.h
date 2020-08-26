#ifndef AUTOMATICROTATION_H
#define AUTOMATICROTATION_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "switchbutton.h"
#include "swichButtonOpenStatus.h"
#include "customstyle_switchNormalStatus.h"

#define KYLIN_AUTOMATICROTATION_NORMAL_NAME     "kylin-bluetooth-normal"
#define KYLIN_AUTOMATICROTATION_HOVER_NAME      "kylin-bluetooth-hover"
#define KYLIN_AUTOMATICROTATION_PRESS_NAME      "kylin-bluetooth-pressed"

#define KYLIN_AUTOMATICROTATION_NORMAL_PATH     ":/image/bluetooth-normal.svg"
#define KYLIN_AUTOMATICROTATION_HOVER_PATH      ":/image/bluetooth-hover.svg"
#define KYLIN_AUTOMATICROTATION_PRESS_PATH      ":/image/bluetooth-pressed.svg"

class AutomaticRotationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AutomaticRotationWidget(QWidget *parent = nullptr);

private:
    void initMemberVariables();
    void initLayout();

private:
    QWidget         *m_pWidgetButton;
    switchButton    *m_pAutomaticRotationButton;
    QLabel          *m_pAutomaticRotationLabel;

    QVBoxLayout     *m_pVboxButtonLayout;
    QVBoxLayout     *m_pVboxLayout;

    QStyle          *m_pStyleOpen;
    QStyle          *m_pStyleNormal;

    QStringList      m_IconPathList;
    QStringList      m_IconNameList;

Q_SIGNALS:

};

#endif // AUTOMATICROTATION_H