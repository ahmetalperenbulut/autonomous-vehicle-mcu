/**
 * \file        mcu_communication_service.cpp
 * \brief       A brief description one line.
 *
 * \author      ahmet.alperen.bulut
 * \date        Aug 17, 2019
 */

/*------------------------------< Includes >----------------------------------*/
#include "CommunicationMechanism.h"
#include "UARTCommunication.h"
#include "UARTMessageBuilder.h"
#include "process.pb.h"
#include <cstring>
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/syslog_sink.h>
#include <spdlog/spdlog.h>
#include <string>
/*------------------------------< Defines >-----------------------------------*/
#define LOGGER_NAME ("mcu_communication_service")

/*------------------------------< Typedefs >----------------------------------*/

/*------------------------------< Namespaces >--------------------------------*/

int main(int argc, char** argv)
{

    std::shared_ptr<spdlog::logger> logger;
    logger = spdlog::get(LOGGER_NAME);
    if (logger == nullptr) {
        logger = spdlog::stdout_color_mt(LOGGER_NAME);
    }

    logger->set_level(spdlog::level::debug);
    if (argc <= 1) {
        logger->critical("UART PORT ERROR");
        exit(1);
    }
    CommunicationMechanism cm(argv[1]);
    cm.waitUntilFinish();
    //sleep(1111);
}