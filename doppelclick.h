#ifndef DOPPELCLICK_H
#define DOPPELCLICK_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
        class Doppelclick;
}

class Doppelclick : public QWidget
{
            Q_OBJECT

        public:
                    explicit Doppelclick(QWidget *parent=0);

        private:
                    void initializeUi(void);
                    QPushButton *doppelButton;

};

#endif // DOPPELCLICK_H
