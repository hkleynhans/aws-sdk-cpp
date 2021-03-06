﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/inspector/model/DescribeAssessmentTemplatesResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Inspector::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

DescribeAssessmentTemplatesResult::DescribeAssessmentTemplatesResult()
{
}

DescribeAssessmentTemplatesResult::DescribeAssessmentTemplatesResult(const AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

DescribeAssessmentTemplatesResult& DescribeAssessmentTemplatesResult::operator =(const AmazonWebServiceResult<JsonValue>& result)
{
  const JsonValue& jsonValue = result.GetPayload();
  if(jsonValue.ValueExists("assessmentTemplates"))
  {
    Array<JsonValue> assessmentTemplatesJsonList = jsonValue.GetArray("assessmentTemplates");
    for(unsigned assessmentTemplatesIndex = 0; assessmentTemplatesIndex < assessmentTemplatesJsonList.GetLength(); ++assessmentTemplatesIndex)
    {
      m_assessmentTemplates.push_back(assessmentTemplatesJsonList[assessmentTemplatesIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("failedItems"))
  {
    Aws::Map<Aws::String, JsonValue> failedItemsJsonMap = jsonValue.GetObject("failedItems").GetAllObjects();
    for(auto& failedItemsItem : failedItemsJsonMap)
    {
      m_failedItems[failedItemsItem.first] = failedItemsItem.second.AsObject();
    }
  }



  return *this;
}
