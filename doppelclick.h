#ifndef DOPPELCLICK_H
#define DOPPELCLICK_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

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
                    QLabel *gameStateLabel;
                    QLabel *gameIcon;
                    
                    /* Global Variables */
                    bool gameState;
                    qint64 startTime;
                    QString bad;
                    QString god;
                    QString neutral;

        private slots:
                    void buttonClicked(void);
};

#endif // DOPPELCLICK_H
