
#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "rapidxml/1.13/rapidxml.hpp"
#include "rapidxml/1.13/rapidxml_print.hpp"
#include "rapidxml/1.13/rapidxml_utils.hpp"
#include "request/auditing_req.h"
#include "response/object_resp.h"

namespace qcloud_cos {

class AuditingResp: public BaseResp {
 public:
  AuditingResp() {}
    
  virtual ~AuditingResp() {}

  virtual bool ParseFromXmlString(const std::string& body);


 protected:
  bool ParseSceneResultInfo(rapidxml::xml_node<>* root, SceneResultInfo& scene_result_info);
  bool ParseJobsDetail(rapidxml::xml_node<>* root, JobsDetail& job_detail);
  bool ParseOcrResultInfo(rapidxml::xml_node<>* root, OcrResult& ocr_results);
  bool ParseLocation(rapidxml::xml_node<>* root, Location& location);
  bool ParseUserInfo(rapidxml::xml_node<>* root, UserInfo& user_info);
  bool ParseSegmentResult(rapidxml::xml_node<>* root, SegmentResult& segment_result);
  bool ParseResults(rapidxml::xml_node<>* root, Result* result);
};

class AuditingJobResp : public AuditingResp {
 public:
  AuditingJobResp() {}
  virtual ~DescribeAuditingJobResp() {}
  virtual bool ParseFromXmlString(const std::string& body);
  virtual bool ParseJobsDetail(rapidxml::xml_node<>* root) { UNUSED_PARAM(root); return true;};
  std::string GetRquestId() const { return m_request_id; }

 protected: 
  std::string request_id;
}

class ImageAuditingResp : public AuditingJobResp {
 public:
  ImageAuditingResp() {}
  virtual ~ImageAuditingResp() {}
  virtual bool ParseFromXmlString(const std::string& body);
  bool ParseJobsDetail(rapidxml::xml_node<>* root, ImageAuditingJobsDetail& jobs_detail);
};

class GetImageAuditingResp : public ImageAuditingResp {
 public:
  GetImageAuditingResp() {}
  virtual ~GetImageAuditingResp() {}
  virtual bool ParseFromXmlString(const std::string& body);

  ImageAuditingJobsDetail GetJobsDetail() const { return m_jobs_detail; }

 private:
  ImageAuditingJobsDetail m_jobs_detail;
};

class BatchImageAuditingResp : public ImageAuditingResp {
 public:
  BatchImageAuditingResp() {}
  virtual ~BatchImageAuditingResp() {}
  virtual bool ParseFromXmlString(const std::string& body);

  ImageAuditingJobsDetail m_jobs_details() const { return m_jobs_details; }


 private: 
  std::vector<ImageAuditingJobsDetail> m_jobs_details;
};


class DescribeImageAuditingJobResp : public ImageAuditingResp {
 public:
  DescribeImageAuditingJobResp() {}
  virtual ~DescribeImageAuditingJobResp() {}
  virtual bool ParseFromXmlString(const std::string& body);
  
  JobsDetail GetJobsDetail() const { return m_jobs_detail; }

 private:
  ImageAuditingJobsDetail m_jobs_detail;
};


class VideoAuditingResp : public AuditingJobResp {
 public:
  VideoAuditingResp() {}
  virtual ~VideoAuditingResp() {}
  virtual bool ParseJobsDetail(rapidxml::xml_node<>* root);
 
  VideoAuditingJobsDetail GetJobsDetail() const { return m_jobs_detail; }
  
 protected:
  VideoAuditingJobsDetail m_jobs_detail;
};

class CreateVideoAuditingJobResp : public VideoAuditingResp {
 public:
  CreateVideoAuditingJobResp() {}
  virtual ~CreateVideoAuditingJobResp() {}  
};

class DescribeVideoAuditingJobResp : public VideoAuditingResp {
 public:
  DescribeVideoAuditingJobResp() {}
  virtual ~DescribeVideoAuditingJobResp() {}
};

class AudioAuditingResp : public AuditingJobResp {
 public:
  AudioAuditingResp() {}
  virtual ~AudioAuditingResp() {}
  virtual bool ParseJobsDetail(rapidxml::xml_node<>* root);
 
  AudioAuditingJobsDetail GetJobsDetail() const { return m_jobs_detail; }
  
 protected:
  AudioAuditingJobsDetail m_jobs_detail;
};

class CreateAudioAuditingJobResp : public AuditingJobResp {
 public:
  CreateAudioAuditingJobResp() {}
  virtual ~CreateAudioAuditingJobResp() {}  
};

class DescribeAudioAuditingJobResp : public AuditingJobResp {
 public:
  DescribeAudioAuditingJobResp() {}
  virtual ~DescribeAudioAuditingJobResp() {}
};

class TextAuditingResp : public AuditingJobResp {
 public:
  TextAuditingResp() {}
  virtual ~TextAuditingResp() {}
  virtual bool ParseJobsDetail(rapidxml::xml_node<>* root);
 
  TextAuditingJobsDetail GetJobsDetail() const { return m_jobs_detail; }
  
 protected:
  TextAuditingJobsDetail m_jobs_detail;
};

class CreateTextAuditingJobResp : public AuditingJobResp {
 public:
  CreateTextAuditingJobResp() {}
  virtual ~CreateTextAuditingJobResp() {}  
};

class DescribeTextAuditingJobResp : public AuditingJobResp {
 public:
  DescribeTextAuditingJobResp() {}
  virtual ~DescribeTextAuditingJobResp() {}
};

class DocumentAuditingResp : public AuditingJobResp {
 public:
  DocumentAuditingResp() {}
  virtual ~DocumentAuditingResp() {}
  virtual bool ParseJobsDetail(rapidxml::xml_node<>* root);
 
  DocumentAuditingJobsDetail GetJobsDetail() const { return m_jobs_detail; }
  
 protected:
  DocumentAuditingJobsDetail m_jobs_detail;
};

class CreateDocumentAuditingJobResp : public AuditingJobResp {
 public:
  CreateDocumentAuditingJobResp() {}
  virtual ~CreateDocumentAuditingJobResp() {}  
};

class DescribeDocumentAuditingJobResp : public AuditingJobResp {
 public:
  DescribeDocumentAuditingJobResp() {}
  virtual ~DescribeDocumentAuditingJobResp() {}
};

class WebPageAuditingResp : public AuditingJobResp {
 public:
  WebPageAuditingResp() {}
  virtual ~WebPageAuditingResp() {}
  virtual bool ParseJobsDetail(rapidxml::xml_node<>* root);
 
  WebPageAuditingJobsDetail GetJobsDetail() const { return m_jobs_detail; }
  
 protected:
  WebPageAuditingJobsDetail m_jobs_detail;
};

class CreateWebPageAuditingJobResp : public AuditingJobResp {
 public:
  CreateWebPageAuditingJobResp() {}
  virtual ~CreateWebPageAuditingJobResp() {}  
};

class DescribeWebPageAuditingJobResp : public AuditingJobResp {
 public:
  DescribeWebPageAuditingJobResp() {}
  virtual ~DescribeWebPageAuditingJobResp() {}
};

}


