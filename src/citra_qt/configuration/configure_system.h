// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <QWidget>
#include "common/common_types.h"

namespace Service {
namespace CFG {
class Module;
} // namespace CFG
} // namespace Service

namespace Ui {
class ConfigureSystem;
} // namespace Ui

class ConfigureSystem : public QWidget {
    Q_OBJECT

public:
    explicit ConfigureSystem(QWidget* parent = nullptr);
    ~ConfigureSystem();

    void applyConfiguration();
    void setConfiguration();
    void retranslateUi();

public slots:
    void updateBirthdayComboBox(int birthmonth_index);
    void refreshConsoleID();

private:
    void ReadSystemSettings();
    bool ValidateCountry();

    std::unique_ptr<Ui::ConfigureSystem> ui;
    bool enabled;

    std::shared_ptr<Service::CFG::Module> cfg;
    std::u16string username;
    int birthmonth, birthday;
    int language_index;
    unsigned char* unknown;
    int country_index;
    int sound_index;
    int model_index;
};
