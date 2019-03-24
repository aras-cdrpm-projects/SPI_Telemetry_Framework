/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <qcgaugewidget.h>
#include "QtQuickWidgets/QQuickWidget"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *POS_TAB;
    QCustomPlot *POS_CHART;
    QComboBox *CAM_SELECTOR;
    QLabel *label_5;
    QLCDNumber *Z_LCD;
    QLabel *label_4;
    QLCDNumber *Y_LCD;
    QLCDNumber *X_LCD;
    QLabel *label_2;
    QWidget *IMU_TAB;
    QComboBox *IMU_SELECTOR;
    QCustomPlot *IMU_CHART;
    QSplitter *splitter_17;
    QSplitter *splitter_16;
    QLabel *label_16;
    QLCDNumber *IMU_X;
    QSplitter *splitter_15;
    QLabel *label_15;
    QLCDNumber *IMU_Y;
    QSplitter *splitter_14;
    QLabel *label_14;
    QLCDNumber *IMU_Z;
    QWidget *FORCE_TAB;
    QcGaugeWidget *FORCE_GAUGE;
    QComboBox *FORCE_SELECTOR;
    QLCDNumber *FORCE_LCD;
    QLabel *label;
    QWidget *ENC_TAB;
    QLCDNumber *ENCODER1_LCD;
    QLabel *label_17;
    QLCDNumber *ENCODER2_LCD;
    QLabel *label_18;
    QLCDNumber *ENCODER3_LCD;
    QLabel *label_19;
    QLCDNumber *ENCODER4_LCD;
    QLabel *label_20;
    QPushButton *L_RESET_BUTTON;
    QTextEdit *L1_PRESET_VAL;
    QTextEdit *L2_PRESET_VAL;
    QTextEdit *L3_PRESET_VAL;
    QTextEdit *L4_PRESET_VAL;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *INIT_TAB;
    QQuickWidget *quickWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 481));
        QFont font;
        font.setPointSize(20);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(100, 20));
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        POS_TAB = new QWidget();
        POS_TAB->setObjectName(QStringLiteral("POS_TAB"));
        POS_CHART = new QCustomPlot(POS_TAB);
        POS_CHART->setObjectName(QStringLiteral("POS_CHART"));
        POS_CHART->setGeometry(QRect(10, 10, 541, 421));
        sizePolicy.setHeightForWidth(POS_CHART->sizePolicy().hasHeightForWidth());
        POS_CHART->setSizePolicy(sizePolicy);
        CAM_SELECTOR = new QComboBox(POS_TAB);
        CAM_SELECTOR->setObjectName(QStringLiteral("CAM_SELECTOR"));
        CAM_SELECTOR->setGeometry(QRect(560, 20, 231, 39));
        label_5 = new QLabel(POS_TAB);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(560, 270, 16, 33));
        Z_LCD = new QLCDNumber(POS_TAB);
        Z_LCD->setObjectName(QStringLiteral("Z_LCD"));
        Z_LCD->setGeometry(QRect(590, 250, 201, 71));
        label_4 = new QLabel(POS_TAB);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(560, 180, 17, 33));
        Y_LCD = new QLCDNumber(POS_TAB);
        Y_LCD->setObjectName(QStringLiteral("Y_LCD"));
        Y_LCD->setGeometry(QRect(590, 160, 201, 71));
        X_LCD = new QLCDNumber(POS_TAB);
        X_LCD->setObjectName(QStringLiteral("X_LCD"));
        X_LCD->setGeometry(QRect(590, 70, 201, 71));
        label_2 = new QLabel(POS_TAB);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 90, 16, 33));
        tabWidget->addTab(POS_TAB, QString());
        IMU_TAB = new QWidget();
        IMU_TAB->setObjectName(QStringLiteral("IMU_TAB"));
        IMU_SELECTOR = new QComboBox(IMU_TAB);
        IMU_SELECTOR->setObjectName(QStringLiteral("IMU_SELECTOR"));
        IMU_SELECTOR->setGeometry(QRect(600, 380, 191, 41));
        IMU_CHART = new QCustomPlot(IMU_TAB);
        IMU_CHART->setObjectName(QStringLiteral("IMU_CHART"));
        IMU_CHART->setGeometry(QRect(10, 10, 771, 341));
        splitter_17 = new QSplitter(IMU_TAB);
        splitter_17->setObjectName(QStringLiteral("splitter_17"));
        splitter_17->setGeometry(QRect(10, 370, 581, 61));
        splitter_17->setOrientation(Qt::Horizontal);
        splitter_16 = new QSplitter(splitter_17);
        splitter_16->setObjectName(QStringLiteral("splitter_16"));
        splitter_16->setOrientation(Qt::Horizontal);
        label_16 = new QLabel(splitter_16);
        label_16->setObjectName(QStringLiteral("label_16"));
        splitter_16->addWidget(label_16);
        IMU_X = new QLCDNumber(splitter_16);
        IMU_X->setObjectName(QStringLiteral("IMU_X"));
        splitter_16->addWidget(IMU_X);
        splitter_17->addWidget(splitter_16);
        splitter_15 = new QSplitter(splitter_17);
        splitter_15->setObjectName(QStringLiteral("splitter_15"));
        splitter_15->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(splitter_15);
        label_15->setObjectName(QStringLiteral("label_15"));
        splitter_15->addWidget(label_15);
        IMU_Y = new QLCDNumber(splitter_15);
        IMU_Y->setObjectName(QStringLiteral("IMU_Y"));
        splitter_15->addWidget(IMU_Y);
        splitter_17->addWidget(splitter_15);
        splitter_14 = new QSplitter(splitter_17);
        splitter_14->setObjectName(QStringLiteral("splitter_14"));
        splitter_14->setOrientation(Qt::Horizontal);
        label_14 = new QLabel(splitter_14);
        label_14->setObjectName(QStringLiteral("label_14"));
        splitter_14->addWidget(label_14);
        IMU_Z = new QLCDNumber(splitter_14);
        IMU_Z->setObjectName(QStringLiteral("IMU_Z"));
        splitter_14->addWidget(IMU_Z);
        splitter_17->addWidget(splitter_14);
        tabWidget->addTab(IMU_TAB, QString());
        FORCE_TAB = new QWidget();
        FORCE_TAB->setObjectName(QStringLiteral("FORCE_TAB"));
        FORCE_GAUGE = new QcGaugeWidget(FORCE_TAB);
        FORCE_GAUGE->setObjectName(QStringLiteral("FORCE_GAUGE"));
        FORCE_GAUGE->setGeometry(QRect(10, 10, 541, 421));
        FORCE_SELECTOR = new QComboBox(FORCE_TAB);
        FORCE_SELECTOR->setObjectName(QStringLiteral("FORCE_SELECTOR"));
        FORCE_SELECTOR->setGeometry(QRect(560, 10, 231, 51));
        FORCE_LCD = new QLCDNumber(FORCE_TAB);
        FORCE_LCD->setObjectName(QStringLiteral("FORCE_LCD"));
        FORCE_LCD->setGeometry(QRect(560, 70, 231, 71));
        label = new QLabel(FORCE_TAB);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(620, 140, 171, 41));
        tabWidget->addTab(FORCE_TAB, QString());
        ENC_TAB = new QWidget();
        ENC_TAB->setObjectName(QStringLiteral("ENC_TAB"));
        ENCODER1_LCD = new QLCDNumber(ENC_TAB);
        ENCODER1_LCD->setObjectName(QStringLiteral("ENCODER1_LCD"));
        ENCODER1_LCD->setGeometry(QRect(10, 2, 301, 71));
        label_17 = new QLabel(ENC_TAB);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(100, 72, 131, 41));
        ENCODER2_LCD = new QLCDNumber(ENC_TAB);
        ENCODER2_LCD->setObjectName(QStringLiteral("ENCODER2_LCD"));
        ENCODER2_LCD->setGeometry(QRect(10, 112, 301, 71));
        label_18 = new QLabel(ENC_TAB);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(100, 182, 131, 41));
        ENCODER3_LCD = new QLCDNumber(ENC_TAB);
        ENCODER3_LCD->setObjectName(QStringLiteral("ENCODER3_LCD"));
        ENCODER3_LCD->setGeometry(QRect(10, 222, 301, 71));
        label_19 = new QLabel(ENC_TAB);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(100, 292, 131, 41));
        ENCODER4_LCD = new QLCDNumber(ENC_TAB);
        ENCODER4_LCD->setObjectName(QStringLiteral("ENCODER4_LCD"));
        ENCODER4_LCD->setGeometry(QRect(10, 332, 301, 71));
        label_20 = new QLabel(ENC_TAB);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(100, 402, 131, 41));
        L_RESET_BUTTON = new QPushButton(ENC_TAB);
        L_RESET_BUTTON->setObjectName(QStringLiteral("L_RESET_BUTTON"));
        L_RESET_BUTTON->setGeometry(QRect(580, 20, 201, 61));
        L1_PRESET_VAL = new QTextEdit(ENC_TAB);
        L1_PRESET_VAL->setObjectName(QStringLiteral("L1_PRESET_VAL"));
        L1_PRESET_VAL->setGeometry(QRect(618, 100, 131, 41));
        L2_PRESET_VAL = new QTextEdit(ENC_TAB);
        L2_PRESET_VAL->setObjectName(QStringLiteral("L2_PRESET_VAL"));
        L2_PRESET_VAL->setGeometry(QRect(618, 180, 131, 41));
        L3_PRESET_VAL = new QTextEdit(ENC_TAB);
        L3_PRESET_VAL->setObjectName(QStringLiteral("L3_PRESET_VAL"));
        L3_PRESET_VAL->setGeometry(QRect(618, 260, 131, 41));
        L4_PRESET_VAL = new QTextEdit(ENC_TAB);
        L4_PRESET_VAL->setObjectName(QStringLiteral("L4_PRESET_VAL"));
        L4_PRESET_VAL->setGeometry(QRect(618, 340, 131, 41));
        label_21 = new QLabel(ENC_TAB);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(628, 140, 161, 41));
        label_22 = new QLabel(ENC_TAB);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(628, 220, 161, 41));
        label_23 = new QLabel(ENC_TAB);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(628, 300, 161, 41));
        label_24 = new QLabel(ENC_TAB);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(628, 380, 161, 41));
        tabWidget->addTab(ENC_TAB, QString());
        INIT_TAB = new QWidget();
        INIT_TAB->setObjectName(QStringLiteral("INIT_TAB"));
        quickWidget = new QQuickWidget(INIT_TAB);
        quickWidget->setObjectName(QStringLiteral("quickWidget"));
        quickWidget->setGeometry(QRect(-1, -11, 801, 451));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        tabWidget->addTab(INIT_TAB, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        CAM_SELECTOR->clear();
        CAM_SELECTOR->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Camera Set1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Camera Set2", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(POS_TAB), QApplication::translate("MainWindow", "Position", Q_NULLPTR));
        IMU_SELECTOR->clear();
        IMU_SELECTOR->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Gyroscope", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Accelerometer", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Magnetometer", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(IMU_TAB), QApplication::translate("MainWindow", "Raw IMU", Q_NULLPTR));
        FORCE_SELECTOR->clear();
        FORCE_SELECTOR->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Force Sensor 1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Force Sensor 2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Force Sensor 3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Force Sensor 4", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "Force (N)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(FORCE_TAB), QApplication::translate("MainWindow", "Force", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Encoder 1", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Encoder 2", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Encoder 3", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Encoder 4", Q_NULLPTR));
        L_RESET_BUTTON->setText(QApplication::translate("MainWindow", "Reset Length", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "L1 Preset", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "L2 Preset", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "L3 Preset", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "L4 Preset", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ENC_TAB), QApplication::translate("MainWindow", "Encoders", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(INIT_TAB), QApplication::translate("MainWindow", "Init Process", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
