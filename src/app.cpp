//
// Created by cpasjuste on 08/12/2021.
//

#include "app.h"

using namespace c2d;

App::App(const c2d::Vector2f &screenSize) : C2DRenderer(screenSize) {
    // add some text
    auto text = new C2DText("libcross2d @ cpasjuste");
    text->setOutlineColor(Color::Red);
    text->setOutlineThickness(1);
    text->setOrigin(Origin::BottomRight);
    text->setPosition(screenSize);
    App::add(text);

    // add a simple rectangle
    rectangle = new C2DRectangle({128, 128});
    rectangle->setFillColor(Color::Orange);
    rectangle->setOutlineColor(Color::Red);
    rectangle->setOutlineThickness(2);
    rectangle->setOrigin(Origin::Center);
    rectangle->setPosition(screenSize.x / 2, screenSize.y / 2);
    App::add(rectangle);
}

// onInput is only called when a key is pressed
bool App::onInput(c2d::Input::Player *players) {
    unsigned int buttons = players[0].buttons;

    // move cube
    if (buttons & Input::Button::Up) {
        rectangle->move({0, -1});
    }
    if (buttons & Input::Button::Down) {
        rectangle->move({0, 1});
    }
    if (buttons & Input::Button::Left) {
        rectangle->move({-1, 0});
    }
    if (buttons & Input::Button::Right) {
        rectangle->move({1, 0});
    }

    // quit app (enter and space on a keyboard)
    if (buttons & Input::Button::Start || buttons & Input::Button::Select || buttons & Input::Button::Quit) {
        quit = true;
    }

    return C2DRenderer::onInput(players);
}

// onUpdate is called every frames
void App::onUpdate() {
    C2DRenderer::onUpdate();
}
