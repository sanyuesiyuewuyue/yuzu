// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <memory>
#include "ui_configure_touchscreen_advanced.h"
#include "yuzu/configuration/config.h"
#include "yuzu/configuration/configure_touchscreen_advanced.h"

ConfigureTouchscreenAdvanced::ConfigureTouchscreenAdvanced(QWidget* parent)
    : QDialog(parent), ui(std::make_unique<Ui::ConfigureTouchscreenAdvanced>()) {
    ui->setupUi(this);

    connect(ui->restore_defaults_button, &QPushButton::clicked, this,
            &ConfigureTouchscreenAdvanced::RestoreDefaults);

    LoadConfiguration();
    resize(0, 0);
}

ConfigureTouchscreenAdvanced::~ConfigureTouchscreenAdvanced() = default;

void ConfigureTouchscreenAdvanced::changeEvent(QEvent* event) {
    if (event->type() == QEvent::LanguageChange) {
        RetranslateUI();
    }

    QDialog::changeEvent(event);
}

void ConfigureTouchscreenAdvanced::RetranslateUI() {
    ui->retranslateUi(this);
}

void ConfigureTouchscreenAdvanced::ApplyConfiguration() {
    Settings::values.touchscreen.finger = ui->finger_box->value();
    Settings::values.touchscreen.diameter_x = ui->diameter_x_box->value();
    Settings::values.touchscreen.diameter_y = ui->diameter_y_box->value();
    Settings::values.touchscreen.rotation_angle = ui->angle_box->value();
}

void ConfigureTouchscreenAdvanced::LoadConfiguration() {
    ui->finger_box->setValue(Settings::values.touchscreen.finger);
    ui->diameter_x_box->setValue(Settings::values.touchscreen.diameter_x);
    ui->diameter_y_box->setValue(Settings::values.touchscreen.diameter_y);
    ui->angle_box->setValue(Settings::values.touchscreen.rotation_angle);
}

void ConfigureTouchscreenAdvanced::RestoreDefaults() {
    ui->finger_box->setValue(0);
    ui->diameter_x_box->setValue(15);
    ui->diameter_y_box->setValue(15);
    ui->angle_box->setValue(0);
}
