#pragma once

namespace Debug
{
	static void Print(const FString& InValue, const FColor& Color = FColor::MakeRandomColor(), int32 InKey = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, 7.f, Color, InValue);

			UE_LOG(LogTemp, Warning, TEXT("%s"), *InValue);
		}
	}

	static void Print(const FString& FloatTitle, float FloatValueToPrint, int32 Inkey = -1, const FColor& Color = FColor::MakeRandomColor())
	{
		if (GEngine)
		{
			const FString FinalMsg = FloatTitle + TEXT(": ") + FString::SanitizeFloat(FloatValueToPrint);

			GEngine->AddOnScreenDebugMessage(Inkey, 7.f, Color, FinalMsg);

			UE_LOG(LogTemp, Warning, TEXT("%s"), *FloatTitle);
		}
	}

}