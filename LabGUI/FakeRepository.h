#pragma once
#include "FileRepository.h"
#include "CVS_HTMLRepository.h"
class FakeFileRepository : public FileRepository
{
public:
	FakeFileRepository(std::vector<Statue>& list);
	std::vector<Statue> GetVector() override;
	~FakeFileRepository();
};

class FakeCSVRepository : public CSV_HTMLRepository
{
public:
	FakeCSVRepository(std::vector<Statue>& list);
	std::vector<Statue> GetVector() override;
	~FakeCSVRepository();
};

