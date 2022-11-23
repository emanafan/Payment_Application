#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	char name[25];
	for (uint8_t i = 0; name[i] = '\0'; i++) {} // a stop condition, body in braces to put code in (NULLCHAR)

	printf("Enter the Card Holder name between 20-24 characters: ");
	char ch;
	uint8_t i = 0;
	while ((ch = getchar()) != '\n') //discard unwanted characters
	{
		name[i] = ch;
		i++;
	}

	int len = strlen(name);
	if (!name)
		return WRONG_NAME;
	if (len > 24 || len < 20)
		return WRONG_NAME;
	else
	{
		for (uint8_t i = 0; i <= len; i++)
		{
			cardData->cardHolderName[i] = name[i];
		}
		return CARD_OK;
	}
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{

	char expDate[100];
	uint8_t cardMonth, cardYear;
	for (uint8_t i = 0; i < 100; i++)
		expDate[i] = '\0';

	printf("Please Enter Your Card Expiry Date in [MM/YY] Formate : ");
	fseek(stdin, 0, SEEK_END);
	FILE* stream;
	if ((stream = fscanf("%s", expDate)) == NULL);
	return;

	if (!expDate)
		return WRONG_EXP_DATE;

	else if (expDate[6] != '\0' || expDate[3] == '\0')
		return WRONG_EXP_DATE;

	else if (expDate[2] != '/')
		return WRONG_EXP_DATE;

	cardMonth = (expDate[0] - '0') * 10 + (expDate[1] - '0');
	cardYear = (expDate[3] - '0') * 10 + (expDate[4] - '0');

	if ((cardMonth > 12 || cardMonth < 1) || (cardYear < 0 || cardYear > 99))
		return WRONG_EXP_DATE;

	for (uint8_t i = 0; i < 6; i++)
		cardData->cardExpirationDate[i] = expDate[i];

	return CARD_OK;
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	char panNumber[30];
	for (uint8_t i = 0; i < 30; i++)
	{
		panNumber[i] = '\0';
	}

	printf("Please Enter Your PAN Number between 16-19 characters : ");

	char pan;
	uint8_t i = 0;
	fseek(stdin, 0, SEEK_END);
	while ((pan = getchar()) != '\n')
	{
		panNumber[i] = pan;
		i++;
	}

	int len = strlen(panNumber);
	if (!panNumber)
		return WRONG_PAN;

	if (len > 19 || len < 16)
		return WRONG_PAN;

	else
	{
		for (uint8_t i = 0; i <= len; i++)
			cardData->primaryAccountNumber[i] = panNumber[i];
		return CARD_OK;
	}
}