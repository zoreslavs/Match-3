#pragma once

class Command
{
public:
	virtual bool Execute() = 0;
	virtual bool UnExecute() = 0;
};
