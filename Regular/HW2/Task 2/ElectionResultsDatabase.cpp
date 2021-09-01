#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        return;
    }

    inputFile >> *this;

    inputFile.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
    return this->sectionVotes.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
    int totalVotesForParty = 0;
    for (int i = 0; i < this->numberOfSections(); i++)
    {
        totalVotesForParty += this->sectionVotes[i].votesForParty(party);
    }
    return totalVotesForParty;
}

Party ElectionResultsDatabase::winningParty() const
{
    int maxVotes = 0;
    Party winningParty = PARTY1;
    int votesForParty1 = this->votesForParty(PARTY1);
    votesForParty1 > maxVotes ? winningParty = PARTY1, maxVotes = votesForParty1 : 0;
    int votesForParty2 = this->votesForParty(PARTY2);
    votesForParty2 > maxVotes ? winningParty = PARTY2, maxVotes = votesForParty2 : 0;
    int votesForParty3 = this->votesForParty(PARTY3);
    votesForParty3 > maxVotes ? winningParty = PARTY3, maxVotes = votesForParty3 : 0;

    return winningParty;
}

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& electionDatabase)
{
    SectionVotes section;
    while (input >> section)
    {
        electionDatabase.sectionVotes.push_back(section);
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, ElectionResultsDatabase& electionDatabase)
{
    for (int i = 0; i < electionDatabase.numberOfSections(); i++)
    {
        output << electionDatabase.sectionVotes[i];
    }
    return output;
}