#include <iostream>
#include "ConverterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"


void writeAnswers(const std::vector<std::vector<RelativeIndex>>& allRequestsResults)
{
    if (allRequestsResults.empty())
    {
        std::cout << "No matches are found.\n";
        return;
    }
    std::vector<std::vector<std::pair<int, float>>> allRequestsResultsReadyForJSON;
    for (auto& requestResult : allRequestsResults)
    {
        std::vector<std::pair<int, float>> requestResultReadyForJSON;
        for (auto& pageRelevance : requestResult)
        {
            std::pair<int, float> relevancePair;
            relevancePair.first = (int) pageRelevance.doc_id;
            relevancePair.second = pageRelevance.rank;
            requestResultReadyForJSON.push_back(relevancePair);
        }
        allRequestsResultsReadyForJSON.push_back(requestResultReadyForJSON);
    }
    ConverterJSON::getInstance()->putAnswers(allRequestsResultsReadyForJSON);
}

int main()
{
    ConverterJSON::getInstance()->readConfigFile();
    ConverterJSON::getInstance()->readRequestFile();
    std::vector<std::string> documents = ConverterJSON::getInstance()->getTextDocuments();
    auto* invertIndex = new InvertedIndex();
    invertIndex->updateDocumentBase(documents);

    std::cout << "Searching!\n";
    SearchServer searchServer(*invertIndex);
    searchServer.setMaxResponses(ConverterJSON::getInstance()->getMaxResponses());
    auto allResults = searchServer.search(ConverterJSON::getInstance()->getRequests());
    writeAnswers(allResults);
    std::cout << "End of search\n";
    std::cin.get();
    return 0;
}