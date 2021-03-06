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

#include <aws/sdb/model/ListDomainsRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::SimpleDB::Model;
using namespace Aws::Utils;

ListDomainsRequest::ListDomainsRequest() : 
    m_maxNumberOfDomains(0),
    m_maxNumberOfDomainsHasBeenSet(false),
    m_nextTokenHasBeenSet(false)
{
}

Aws::String ListDomainsRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=ListDomains&";
  if(m_maxNumberOfDomainsHasBeenSet)
  {
    ss << "MaxNumberOfDomains=" << m_maxNumberOfDomains << "&";
  }

  if(m_nextTokenHasBeenSet)
  {
    ss << "NextToken=" << StringUtils::URLEncode(m_nextToken.c_str()) << "&";
  }

  ss << "Version=2009-04-15";
  return ss.str();
}


void  ListDomainsRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
