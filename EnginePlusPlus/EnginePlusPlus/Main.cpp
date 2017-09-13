#include "LogManagerPlusPlus.cpp"
#include "ClockPlusPlus.cpp"
#include <iostream>
int main(int argc, char* argcs[]) {

	//we start by calling the clock
	Clock::init();



	//enum LogSeverity { LOG_NONE, LOG_CRIT, LOG_ERROR, LOG_WARN, LOG_TRACE, LOG_INFO, LOG_DEBUG };
	LogManager::getInstance().setSeverity(LogManager::LogSeverity::LOG_DEBUG);
	
	LogManager::getInstance().warn("danger will robinson");
	LogManager::getInstance().info("just thought you should know...");
	LogManager::getInstance().trace("Overwatch");
	LogManager::getInstance().debug("new engine system works");


	

	if (Clock::isReady()) {
		LogManager::getInstance().debug("Clock Ready for use!");
		LogManager::getInstance().info(std::to_string(Clock::getCurrentTime()));
		LogManager::getInstance().info("It has been approximately " + std::to_string(Clock::getCTimeInHours()) + " hours since this computer was turned on.");
	}
	else { LogManager::getInstance().critError("Clock failed to initialize."); }

	while (true) {
		std::cout << std::to_string(Clock::getGameRuntime()) << " seconds since the game started running" << std::endl;
	}
	
	

	return 0;
}