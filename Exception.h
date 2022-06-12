//
// Created by Nadav Koplovich on 08/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class DeckFileNotFound : public std::exception{};

class DeckFileFormatError : public std::exception{};

class DeckFileInvalidSize : public std::exception{};

#endif //EX4_EXCEPTION_H
