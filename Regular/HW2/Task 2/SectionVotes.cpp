#include "SectionVotes.hpp"

SectionVotes::SectionVotes() : partyVotes()
{ }

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{ 
	this->partyVotes[PARTY1] = party1Votes;
	this->partyVotes[PARTY2] = party2Votes;
	this->partyVotes[PARTY3] = party3Votes;
}

int SectionVotes::votesForParty(Party party) const
{
	return this->partyVotes[party];
}

std::istream& operator>>(std::istream& input, SectionVotes& section)
{
	int party1, party2, party3;
	input >> party1 >> party2 >> party3;
	section = SectionVotes(party1, party2, party3);
	return input;
}

std::ostream& operator<<(std::ostream& output, SectionVotes& section)
{
	return output << section.votesForParty(PARTY1) << ' ' << section.votesForParty(PARTY2) << ' ' << section.votesForParty(PARTY3) << std::endl;
}
