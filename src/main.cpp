///  Copyright 2021 RISE Research Institute of Sweden - Maritime Operations
///
///  Licensed under the Apache License, Version 2.0 (the "License");
///  you may not use this file except in compliance with the License.
///  You may obtain a copy of the License at
///
///      http://www.apache.org/licenses/LICENSE-2.0
///
///  Unless required by applicable law or agreed to in writing, software
///  distributed under the License is distributed on an "AS IS" BASIS,
///  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
///  See the License for the specific language governing permissions and
///  limitations under the License.
#include <filesystem>
#include <iostream>
#include <optional>

#include "CLI/CLI.hpp"
#include "cluon/OD4Session.hpp"
#include "cluon/UDPReceiver.hpp"

auto main(int argc, char **argv) -> int {
  CLI::App app{"UDP sniffer"};

  std::string address;
  app.add_option("-a,--address", address, "IP address of stream")->required();
  uint16_t port;
  app.add_option("-p,--port", port, "Port number to connect to")->required();
  std::string interface_address = "";
  app.add_option("-i,--interfaceaddress", interface_address,
                 "IP address associated with the interface to be used");

  CLI11_PARSE(app, argc, argv);

  // Setup a connection to an UDP source
  cluon::UDPReceiver connection{
      address, port,
      [](std::string &&d, std::string && /*from*/,
         std::chrono::system_clock::time_point &&tp) noexcept {
        std::cout << d << std::endl;
      },
      0, interface_address};

  using namespace std::literals::chrono_literals;  // NOLINT
  while (connection.isRunning()) {
    std::this_thread::sleep_for(1s);
  }

  return 0;
}
