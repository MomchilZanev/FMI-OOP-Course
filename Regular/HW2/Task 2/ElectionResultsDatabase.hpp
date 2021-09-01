#pragma once
#include <vector>
#include "SectionVotes.hpp"
#include <fstream>

class ElectionResultsDatabase
{
public:
    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
    friend std::ostream& operator<<(std::ostream&, ElectionResultsDatabase&);

    void addResultsFromFile(const char* filename);
    int numberOfSections() const;
    int votesForParty(Party) const;
    Party winningParty() const;
private:
    std::vector<SectionVotes> sectionVotes;
};