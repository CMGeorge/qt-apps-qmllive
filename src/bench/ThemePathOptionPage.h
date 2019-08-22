#ifndef THEMEPATHOPTIONPAGE_H
#define THEMEPATHOPTIONPAGE_H

#include <QWidget>

namespace Ui {
class ThemePathOptionPage;
}

class ThemePathOptionPage : public QWidget
{
    Q_OBJECT

public:
    explicit ThemePathOptionPage(QWidget *parent = nullptr);
    ~ThemePathOptionPage();
    void apply();

private slots:
    void on_btnClear_clicked();

    void on_btnBrowse_clicked();

private:
    Ui::ThemePathOptionPage *ui;
};

#endif // THEMEPATHOPTIONPAGE_H
