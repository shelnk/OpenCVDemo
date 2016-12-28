
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
using namespace cv;

int main( int argc, char** argv )
{
  //����IplImageָ��
  IplImage* pImg = NULL; 
  IplImage* pContourImg = NULL;

const char* filename=("D:\\Projects\\OpencvTest\\OpencvTest\\PP4.JPG");
pImg = cvLoadImage(filename, 0);

//  pImg=cvLoadImage(filename,1);

  CvMemStorage * storage = cvCreateMemStorage(0);
  CvSeq * contour = 0;
  int mode = CV_RETR_EXTERNAL;
 mode = CV_RETR_CCOMP;
  if( argc == 3)
      if(strcmp(argv[2], "all") == 0)
	mode = CV_RETR_CCOMP; //�������������
      

  //��������
  cvNamedWindow("src", 1);
  cvNamedWindow("contour",1);



  //����ͼ��ǿ��ת��ΪGray
  if( 1)// && 
      //(pImg = cvLoadImage(filename, 0)) != 0 )
    {
		pImg = cvLoadImage(filename, 0);
      cvShowImage( "src", pImg );

      //Ϊ������ʾͼ������ռ�
      //3ͨ��ͼ���Ա��ò�ɫ��ʾ
      pContourImg = cvCreateImage(cvGetSize(pImg),
					  IPL_DEPTH_8U,
					  3);
      //copy source image and convert it to BGR image
      cvCvtColor(pImg, pContourImg, CV_GRAY2BGR);

//	  IplImage *pBinaryImage = cvCreateImage(cvGetSize(pContourImg), IPL_DEPTH_8U, 1); 
//  cvThreshold(pContourImg, pBinaryImage, 250, 255, CV_THRESH_BINARY);
	  cvThreshold(pImg, pImg, 128, 255,CV_THRESH_BINARY);


      //����contour
      cvFindContours( pImg/*pBinaryImage/*pImg*/, storage, &contour, sizeof(CvContour), 
		  mode, 5);//CV_CHAIN_APPROX_SIMPLE);

    }
  else
    {
      //���ٴ���
      cvDestroyWindow( "src" );
      cvDestroyWindow( "contour" );
      cvReleaseMemStorage(&storage);
	 
      return -1;
    }




  //����������    
  cvDrawContours(pContourImg, contour, 
		 CV_RGB(0,0,255), CV_RGB(255, 0, 0), 
		 2, 2, 8);
  //��ʾͼ��
  cvShowImage( "contour", pContourImg );

  cvWaitKey(0);


  //���ٴ���
  cvDestroyWindow( "src" );
  cvDestroyWindow( "contour" );
  //�ͷ�ͼ��
  cvReleaseImage( &pImg ); 
  cvReleaseImage( &pContourImg ); 

  cvReleaseMemStorage(&storage);

  return 0;
}
 