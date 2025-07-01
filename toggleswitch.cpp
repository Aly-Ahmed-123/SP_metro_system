
#include "toggleswitch.h"
#include <QPainter>
#include <QMouseEvent>

ToggleSwitch::ToggleSwitch(QWidget *parent) : QAbstractButton(parent), m_offset(0.0) {
    setCheckable(true);
    animation = new QPropertyAnimation(this, "offset", this);
    animation->setDuration(200);
    connect(this, &QAbstractButton::toggled, [=](bool checked) {
        animation->stop();
        animation->setStartValue(m_offset);
        animation->setEndValue(checked ? 1.0 : 0.0);
        animation->start();
    });
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    resize(sizeHint());
}

QSize ToggleSwitch::sizeHint() const {
    return QSize(60, 30);
}

qreal ToggleSwitch::offset() const {
    return m_offset;
}

void ToggleSwitch::setOffset(qreal value) {
    m_offset = value;
    update();
}

void ToggleSwitch::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QRectF bgRect = rect();
    QColor bgColor = isChecked() ? QColor("#4caf50") : QColor("#ccc");
    p.setBrush(bgColor);
    p.setPen(Qt::NoPen);
    p.drawRoundedRect(bgRect, height()/2, height()/2);

    qreal knobRadius = height() * 0.8 / 2;
    qreal xPos = m_offset * (width() - 2 * knobRadius - 8);
    QRectF knobRect(4 + xPos, (height() - knobRadius*2)/2, knobRadius*2, knobRadius*2);
    p.setBrush(Qt::white);
    p.drawEllipse(knobRect);
}
