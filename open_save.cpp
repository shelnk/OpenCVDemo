//#include "cv.h"
//#include "highgui.h"
//
//int main( int argc, char** argv )
//{
//	IplImage* pImg; //����IplImageָ��
//	const char* filename = "D:\\Projects\\OpencvTest\\OpencvTest\\pp.jpg";
//
//	//����ͼ��
//	if( argc == 2 && 
//		(pImg = cvLoadImage(filename, CV_LOAD_IMAGE_COLOR)) != 0 )
//	{
//		cvNamedWindow( "Image", 1 );//��������
//		cvShowImage( "Image", pImg );//��ʾͼ��
//
//		cvWaitKey(0); //�ȴ�����
//
//		cvDestroyWindow( "Image" );//���ٴ���
//		cvReleaseImage( &pImg ); //�ͷ�ͼ��
//		return 0;
//	}
//
//	return -1;
//}
//
