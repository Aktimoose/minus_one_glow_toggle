
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJGarageLayer.hpp>
class $modify(MyGJGarageLayer, GJGarageLayer) {

	bool init() {
		if (!GJGarageLayer::init()) {
			return false;
		}

		// Makes the button "glowSwitch"
		auto glowSwitch = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_featuredCoin_001.png"),
			this,

			menu_selector(MyGJGarageLayer::onGlowToggle)
		);

		// Put it in the left menu in the icon kit
		auto menu = this->getChildByID("shards-menu");
		menu->addChild(glowSwitch);

		glowSwitch->setID("glow-switch"_spr);

		menu->updateLayout();

		return true;
	}

	void onGlowToggle(CCObject*) {
 	   auto gm = GameManager::get();

        // Set glow color to -1
		gm->m_playerGlowColor = -1;

		FLAlertLayer::create("Success!", "Set the Glow Color to -1!", "OK")->show();
	}
};