//
// Created by cpasjuste on 08/12/2021.
//

#include "app.h"

using namespace c2d;

App::App(const c2d::Vector2f &screenSize) : C2DRenderer(screenSize) {
    // add some text
    auto text = new Text("libcross2d @ cpasjuste");
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
    unsigned int keys = players[0].keys;

    // move cube
    if (keys & Input::Key::Up) {
        rectangle->move({0, -1});
    }
    if (keys & Input::Key::Down) {
        rectangle->move({0, 1});
    }
    if (keys & Input::Key::Left) {
        rectangle->move({-1, 0});
    }
    if (keys & Input::Key::Right) {
        rectangle->move({1, 0});
    }

    // quit app (enter and space on a keyboard)
    if (keys & Input::Key::Start || keys & Input::Key::Select || keys & EV_QUIT) {
        quit = true;
    }

    return C2DRenderer::onInput(players);
}

// onUpdate is called every frames
void App::onUpdate() {
    C2DRenderer::onUpdate();
}
