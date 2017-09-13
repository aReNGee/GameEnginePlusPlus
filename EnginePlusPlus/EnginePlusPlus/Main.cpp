#include "LogManagerPlusPlus.cpp"
int main(int argc, char* argcs[]) {

	//enum LogSeverity { LOG_NONE, LOG_CRIT, LOG_ERROR, LOG_WARN, LOG_TRACE, LOG_INFO, LOG_DEBUG };
	LogManager::getInstance().setSeverity(LogManager::LogSeverity::LOG_DEBUG);
	
	//LogManager::getInstance().warn("danger will robinson");
	LogManager::getInstance().info("just thought you should know...");
	//LogManager::getInstance().trace("Overwatch");
	LogManager::getInstance().debug("new engine system works");
	LogManager::getInstance().error("huh");
	LogManager::getInstance().critError("Critical Error");
	

	return 0;
}