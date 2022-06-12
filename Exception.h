//
// Created by Nadav Koplovich on 08/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class DeckNotFound : public std::exception
{
    public:
    string what()
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public  std::exception
{
    int m_line;

    public:
    DeckFileFormatError(int line):
        m_line(line)
    {}

    string what()
    {
        return "Deck File Error: File format error in line " + m_line;
    }
};

class DeckFileInvalidSize : public std::exception
{
    public:
    string what()
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif //EX4_EXCEPTION_H
