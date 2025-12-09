#include "mainwindow.h"
#include "Team.hpp"
#include "./ui_mainwindow.h"

extern vector<Team *>	teams;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CreateTeam_clicked()
{
    QString mapName;

    ui->Pages->setCurrentIndex(4);
    ui->label_2->hide();
    for (size_t i = 0; i < _maps.size(); i++)
    {
        mapName.assign(_maps[i]);
        ui->MapSelect->addItem(mapName);
    }
    // string input;
    // std::cout << RESET << BCYAN << "Choose team name\n" << RESET;
    // std::cin >> input;
    // teams.push_back(new Team(input));
    // teams[teams.size() - 1]->newTeam();
    // while (1)
    // {
    //     std::cout << HIWHITE << "Add more comps? Y/n:" << RESET;
    //     std::cin >> input;
    //     std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    //     if (input == "Y")
    //         teams[teams.size() - 1]->newTeam();
    //     else
    //     {
    //         std::cout << (*(teams.end())) << "\n";
    //         break ;
    //     }
    // }
}


void MainWindow::on_EditTeam_clicked()
{
    QString temp;

    ui->EditTeamSel->blockSignals(true);
    ui->EditCompSel->blockSignals(true);
    qDebug() << "Start\n";
    ui->Pages->setCurrentIndex(3);
    ui->EditTeamSel->clear();
    ui->EditCompSel->clear();
    for (size_t i = 0; i < teams.size(); i++)
    {
        temp.assign(teams[i]->getName());
        ui->EditTeamSel->addItem(temp);
    }
    ui->EditTeamSel->blockSignals(false);
    ui->EditCompSel->blockSignals(false);
    ui->EditTeamSel->currentIndexChanged(0);
    ui->EditCompSel->setCurrentIndex(0);
}

void MainWindow::on_ViewStats_clicked()
{
    QString teams_list;
    string  str_teams;

    for (size_t i = 0; i < teams.size(); i++)
    {
        str_teams = teams[i]->getName() + "\n";
        teams_list.assign(str_teams);
        ui->TeamSelectStats->addItem(teams_list);
    }
    ui->Pages->setCurrentIndex(1);
}


void MainWindow::on_BackMap_clicked()
{
    ui->Pages->setCurrentIndex(0);
}


void MainWindow::on_BackStats_clicked()
{
    ui->Pages->setCurrentIndex(0);
}


void MainWindow::on_BackEdit_clicked()
{
    ui->Pages->setCurrentIndex(0);
}


void MainWindow::on_BackCreate_clicked()
{
    ui->Pages->setCurrentIndex(0);
}


void MainWindow::on_BackDel_clicked()
{
    ui->Pages->setCurrentIndex(0);
}


void MainWindow::on_ViewMap_clicked()
{
    ui->Pages->setCurrentIndex(5);
}


void MainWindow::on_saveteam_clicked()
{
    QString qname = ui->teamName->text();
    string  name = qname.toStdString();
    string  heroes[6];
    std::cout << "Saving new team " << name << "\n";
    int tank = ui->tank->currentIndex();
    int dps1 = ui->dps1->currentIndex();
    int dps2 = ui->dps2->currentIndex();
    int supp1 = ui->supp1->currentIndex();
    int supp2 = ui->supp2->currentIndex();
    int map = ui->MapSelect->currentIndex();

    heroes[0] = "TANK:" + _heroes[tank];
    heroes[1] = "DPS1:" + _heroes[dps1 + 13];
    heroes[2] = "DPS2:" + _heroes[dps2 + 13];
    heroes[3] = "SUPP1:" + _heroes[supp1 + 32];
    heroes[4] = "SUPP2:" + _heroes[supp2 + 32];
    heroes[5] = "MAP:" + _maps[map];
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (teams[i]->getName() == name)
        {
            (*(teams.end() - 1))->addComp(heroes);
            return ;
        }
    }
    teams.push_back(new Team(name));
    (*(teams.end() - 1))->addComp(heroes);
    ui->label_2->show();
}



void MainWindow::on_Pages_currentChanged(int arg1)
{

}


void MainWindow::on_TeamSelectStats_currentIndexChanged(int index)
{
    QString stats;
    string  stats_str;

    ui->StatsMap->setCurrentIndex(0);
    stats_str = teams[index]->retStats();
    stats.assign(stats_str);
    ui->StatsInfo->setText(stats);
}


void MainWindow::on_StatsMap_currentIndexChanged(int index)
{
    QString stats;
    QString comp;
    string stats_str;

    if (index == 0)
    {
        ui->StatsMap->setCurrentIndex(0);
        stats_str = teams[index]->retStats();
        stats.assign(stats_str);
        ui->StatsInfo->setText(stats);
        return ;
    }
    stats_str = teams[ui->TeamSelectStats->currentIndex()]->retMapStats(index - 1);
    qDebug() << stats_str << "\n";
    comp.assign(stats_str.substr(stats_str.find("\n") + 1));
    stats.assign(stats_str.substr(0, stats_str.find("\n") + 1));
    stats.append("\n");
    comp.append("\n");
    ui->StatsInfo->setTextColor(Qt::black);
    ui->StatsInfo->setFontWeight(QFont::Bold);
    ui->StatsInfo->setText(comp);
    ui->StatsInfo->setTextColor(Qt::red);
    ui->StatsInfo->setFontWeight(QFont::Normal);
    ui->StatsInfo->insertPlainText(stats);
}


void MainWindow::on_EditTeamSel_currentIndexChanged(int index)
{
    QString temp;

    ui->EditCompSel->clear();
    ui->EditCompSel->blockSignals(true);
    qDebug() << teams[index]->getCompAmt() << " amount\n";
    for (size_t i = 0; i < teams[index]->getCompAmt(); i++)
    {
        temp.assign("Comp ");
        temp.append(to_string(i));
        ui->EditCompSel->addItem(temp);
    }
    ui->EditCompSel->blockSignals(false);
    ui->EditCompSel->currentIndexChanged(0);
}


void MainWindow::on_EditCompSel_currentIndexChanged(int index)
{
    int heroIndex;
    bool    dps1 = false;
    bool    supp1 = false;
    string  *comp;

    if (index < 0)
        return ;
    ui->EditTankSel->blockSignals(true);
    ui->EditDps1Sel->blockSignals(true);
    ui->EditDps2Sel->blockSignals(true);
    ui->EditSupp1Sel->blockSignals(true);
    ui->EditSupp2Sel->blockSignals(true);
    comp = teams[ui->EditTeamSel->currentIndex()]->getComp(index);
    if (comp == NULL)
    {
        qDebug() << "NULL COMP\n";
         return ;
    }
    for (size_t i = 0; i < 6; i++)
    {
        auto it = ::find(_heroes.begin(), _heroes.end(), comp[i]);
        if (it == _heroes.end())
        {
            auto map_it = ::find(_maps.begin(), _maps.end(), comp[i]);
            if (map_it == _maps.end())
            {
                qDebug() << "Invalid input?" << comp[i] << "\n";
                continue ;
            }
            else
            {
                ui->EditMapSel->setCurrentIndex(::distance(_maps.begin(), map_it));
                continue;
            }
        }
        heroIndex = ::distance(_heroes.begin(), it);
        if (heroIndex < 13)
            ui->EditTankSel->setCurrentIndex(heroIndex);
        else if (heroIndex < 32 && !dps1)
        {
            ui->EditDps1Sel->setCurrentIndex(heroIndex - 13);
            dps1 = true;
        }
        else if (heroIndex < 32)
        {
            ui->EditDps2Sel->setCurrentIndex(heroIndex - 13);
            dps1 = false;
        }
        else if (!supp1)
        {
            ui->EditSupp1Sel->setCurrentIndex(heroIndex - 32);
            supp1 = true;
        }
        else
        {
            ui->EditSupp2Sel->setCurrentIndex(heroIndex - 32);
            supp1 = false;
        }
    }
    delete [] comp;
    ui->EditTankSel->blockSignals(false);
    ui->EditDps1Sel->blockSignals(false);
    ui->EditDps2Sel->blockSignals(false);
    ui->EditSupp1Sel->blockSignals(false);
    ui->EditSupp2Sel->blockSignals(false);
}


void MainWindow::on_EditTankSel_currentIndexChanged(int index)
{
    EditComp();
}

void MainWindow::EditComp()
{
    int  heroes[5];

    heroes[0] = ui->EditTankSel->currentIndex();
    heroes[1] = ui->EditDps1Sel->currentIndex();
    heroes[2] = ui->EditDps2Sel->currentIndex();
    heroes[3] = ui->EditSupp1Sel->currentIndex();
    heroes[4] = ui->EditSupp2Sel->currentIndex();
    teams[ui->EditTeamSel->currentIndex()]->changeComp(heroes, ui->EditCompSel->currentIndex());
}

void MainWindow::on_EditDps1Sel_currentIndexChanged(int index)
{
    EditComp();
}


void MainWindow::on_EditDps2Sel_currentIndexChanged(int index)
{
    EditComp();
}


void MainWindow::on_EditSupp1Sel_currentIndexChanged(int index)
{
    EditComp();
}


void MainWindow::on_EditSupp2Sel_currentIndexChanged(int index)
{
    EditComp();
}


void MainWindow::on_EditCompSel_activated(int index)
{

}


void MainWindow::on_AddCompMenu_clicked()
{
    QString teams_list;
    string  str_teams;
    ui->Pages->setCurrentIndex(2);
    ui->TeamSelectStats->blockSignals(true);
    ui->TeamSelectStats->clear();
    for (size_t i = 0; i < teams.size(); i++)
    {
        str_teams = teams[i]->getName() + "\n";
        teams_list.assign(str_teams);
        ui->TeamSelectStats->addItem(teams_list);
    }
    ui->TeamSelectStats->blockSignals(false);
}


void MainWindow::on_AddComp_clicked()
{
    QString qname = ui->teamName->text();
    string  name = qname.toStdString();
    string  heroes[6];
    int tank = ui->AddTank->currentIndex();
    int dps1 = ui->AddDps1->currentIndex();
    int dps2 = ui->AddDps2->currentIndex();
    int supp1 = ui->AddSupp1->currentIndex();
    int supp2 = ui->AddSupp2->currentIndex();
    int map = ui->AddMap->currentIndex();
    int team = ui->AddTeamSel->currentIndex();

    heroes[0] = "TANK:" + _heroes[tank];
    heroes[1] = "DPS1:" + _heroes[dps1 + 13];
    heroes[2] = "DPS2:" + _heroes[dps2 + 13];
    heroes[3] = "SUPP1:" + _heroes[supp1 + 32];
    heroes[4] = "SUPP2:" + _heroes[supp2 + 32];
    heroes[5] = "MAP:" + _maps[map];
    teams[team]->addComp(heroes);
    ui->SavedComp->show();
    auto lambda = ui->AddComp;
    QTimer::singleShot(5000, this, [this, lambda]()
    {
        ui->SavedComp->hide();
    });
}

