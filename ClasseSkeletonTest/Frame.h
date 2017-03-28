#ifndef DEF_FRAME
#define DEF_FRAME


#include "includes.h"
#include "Skeleton.h"
#include "Bone.h"

class Frame
{

	public:
		/************CONSTRUCTION***********/
	Frame();
	Frame(const Frame& F);


		/************METHODES************/

			/****GETTERS****/
// Get le numéro de frame
	Output_GetFrameNumber getFrameNumber() const;

// Get le framerate
	Output_GetFrameRate getFrameRate() const;

// Get le timecode
	Output_GetTimecode getFrameTimeCode() const;

// Get le nombre de Skeleton dans la Frame
	unsigned int getSkeletonCount() const;

// Get la Frame (collection de Skeleton)
	std::vector<Skeleton> getFrameSkeletons() const;

			/****SETTERS****/

// Set le nouveau Skeleton (collection de bone)
	void setFrame(const Client& MyClient);


	
		/************DESTRUCTEUR***********/
	~Frame();

	
		/************FRIENDS**************/

	friend ostream& operator<<(ostream& flux, const Frame& F);


	private:

// Le numéro de la frame 
	Output_GetFrameNumber m_frameNumber;

// Le framerate
	Output_GetFrameRate m_frameRate;

// Le timecode 
	Output_GetTimecode m_frameTimeCode;

// Nombre de Skeleton dans la Frame 
	unsigned int m_skeletonCount;

// L'ensemble des Skeleton composant la Frame
	std::vector<Skeleton> m_frameSkeleton;
};
