#ifndef DOPPELCLICK_H
#define DOPPELCLICK_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

namespace Ui {
        class Doppelclick;
}

class Doppelclick : public QWidget
{
            Q_OBJECT

        public:
                    explicit Doppelclick(QWidget *parent=0);

        private:
                    /* private Methodes */
                    void initializeUi(void);

                    /* GUI Elements */
                    QPushButton *doppelButton;
                    QLabel *gameState;

};

#endif // DOPPELCLICK_H
