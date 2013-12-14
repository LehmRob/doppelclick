#include <QtWidgets>
#include <QPushButton>
#include <QVBoxLayout>

#include "doppelclick.h"

Doppelclick::Doppelclick (QWidget *parent) :
        QWidget(parent) 
{
        initializeUi();
}

/**
 * Initialize the User interface
 */
void Doppelclick::initializeUi(void) {
        doppelButton = new QPushButton("Doppelclick");

        setWindowTitle("Doppelclick Spiel");

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setObjectName("MainLayout");

        mainLayout->addWidget(doppelButton);
}
