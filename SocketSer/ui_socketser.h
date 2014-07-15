/********************************************************************************
** Form generated from reading UI file 'socketser.ui'
**
** Created: Mon Jul 14 19:39:59 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETSER_H
#define UI_SOCKETSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_socketser
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *socketser)
    {
        if (socketser->objectName().isEmpty())
            socketser->setObjectName(QString::fromUtf8("socketser"));
        socketser->resize(400, 338);
        layoutWidget = new QWidget(socketser);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 30, 335, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(socketser);

        QMetaObject::connectSlotsByName(socketser);
    } // setupUi

    void retranslateUi(QWidget *socketser)
    {
        socketser->setWindowTitle(QApplication::translate("socketser", "socketser", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("socketser", "Receive Information", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("socketser", "Start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class socketser: public Ui_socketser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETSER_H
