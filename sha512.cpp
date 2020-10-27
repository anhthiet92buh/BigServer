// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      sha256.cpp
/// @brief     Calculate and display the SHA-256 hash of a list of files.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      October 10, 2017
/// @copyright (c) 2017 Nabla Zero Labs
/// @license   MIT License
///
/// Compiled in macOS High Sierra 10.13 (previous installation of OpenSSL 1.1.0).
///
///     $ clang++ sha256.cpp -osha256 -std=c++1z -Wall -Wextra -march=native \
///       -Ofast -lssl -lcrypto
///     $ ./sha256
///       usage: ./sha256 FILE_1 [FILE_2 [... [FILE_N]]]
///     $ ./sha256 sha256
///       f4774d172b9177109045759ada55f55a47a602c0b0392330d5c4b79e9d474fb0 sha256
///

// C++ Standard Library
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>

// OpenSSL Library
#include <openssl/sha.h>

inline std::string
SHA256(const char* const path)
{
  std::ifstream fp(path, std::ios::in | std::ios::binary);

  if (not fp.good()) {
    std::ostringstream os;
    os << "Cannot open \"" << path << "\": " << std::strerror(errno) << ".";
    throw std::runtime_error(os.str());
  }

  constexpr const std::size_t buffer_size { 1 << 12 };
  char buffer[buffer_size];

  unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };

  SHA256_CTX ctx;
  SHA256_Init(&ctx);

  while (fp.good()) {
    fp.read(buffer, buffer_size);
    SHA256_Update(&ctx, buffer, fp.gcount());
  }

  SHA256_Final(hash, &ctx);
  fp.close();

  std::ostringstream os;
  os << std::hex << std::setfill('0');

  for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
    os << std::setw(2) << static_cast<unsigned int>(hash[i]);
  }

  return os.str();
}

int
main(int argc, char* argv[])
{

  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " FILE_1 [FILE_2 [... [FILE_N]]]" << std::endl;
    return EXIT_FAILURE;
  }

  for (int arg = 1; arg < argc; ++arg) {
    try {
      std::cout << SHA256(argv[arg]) << " " << argv[arg] << std::endl;
    } catch(const std::exception& e) {
      std::cerr << "[fatal] " <<  e.what() << std::endl;
    }
  }

  return EXIT_SUCCESS;
  
}