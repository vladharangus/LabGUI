#include "pch.h"
#include "FakeRepository.h"


FakeFileRepository::FakeFileRepository(std::vector<Statue>& list) : FileRepository("", list)
{
}

std::vector<Statue> FakeFileRepository::GetVector()
{
	return Repository::GetVector();
}

FakeFileRepository::~FakeFileRepository()
{
}

FakeCSVRepository::FakeCSVRepository(std::vector<Statue>& list) : CSV_HTMLRepository(list)
{
}

std::vector<Statue> FakeCSVRepository::GetVector()
{
	return Repository::GetVector();
}

FakeCSVRepository::~FakeCSVRepository()
{
}
