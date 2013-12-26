#ifndef DOPPELCLICK_TIME_H
#define DOPPELCLICK_TIME_H

#include <QWidget>

class DoppelclickTime
{
        public:
                DoppelclickTime(void);
                DoppelclickTime(qint64 startTime);
                qint64 getDiffTime(void);

        private:
                qint64 startTime;
                qint64 stopTime;
};
#endif /* DOPPELCLICK_TIME_H */
