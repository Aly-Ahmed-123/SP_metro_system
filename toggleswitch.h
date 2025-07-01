
#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QAbstractButton>
#include <QPropertyAnimation>

class ToggleSwitch : public QAbstractButton {
    Q_OBJECT
    Q_PROPERTY(qreal offset READ offset WRITE setOffset)

public:
    explicit ToggleSwitch(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    qreal offset() const;
    void setOffset(qreal value);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    qreal m_offset;
    QPropertyAnimation *animation;
};

#endif // TOGGLESWITCH_H
