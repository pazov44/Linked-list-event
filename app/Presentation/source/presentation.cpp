#include "pch.h"
#include "presentation.h"
#include "access.h"
#include "business.h"
#include "core.h"
namespace Presentation
{
	bool Init()
	{
		if (!Core::Init())
			return false;
		if (!Access::Init())
			return false;
		if (!Business::Init())
			return false;
		return true;
	}
	bool Release()
	{
		if (!Core::Release())
			return false;
		if (!Access::Release())
			return false;
		if (!Business::Release())
			return false;
		return true;
	}
}