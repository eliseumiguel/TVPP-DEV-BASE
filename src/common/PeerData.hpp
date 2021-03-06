#ifndef PEERDATA_H_INCLUDED
#define PEERDATA_H_INCLUDED

#include <string>
#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include "HeadedBitset.hpp"
#include "Defines.hpp"
#include "Peer.hpp"
#include "ChunkUniqueID.hpp"

using namespace std;


typedef std::pair<std::string, uint32_t> PairStrInt;
typedef std::pair<TopologyClasses, uint32_t> PairTopologyInt;

/**
* This class implements the information about the peers
*/
class PeerData
{
    public:
        /**
        * @param string
        * @param int Max TTL value
        */
        PeerData(Peer* p = NULL, int ttlIn = TTLIn, int ttlOut = TTLOut, int ttlChannel = TTLChannel, int size = STD_BUFFERSIZE);
        
        Peer* GetPeer();
        
        /**
        * This method returns the current TTL value
        * @return A string with the
        */
        //ECM
        int GetTTLIn();
        void SetTTLIn(int v);
        void DecTTLIn();

        int GetTTLOut(bool peerListOut_free);
        void SetTTLOut(int v, bool peerListOut_free);
        void DecTTLOut(bool peerListOut_free);

        int GetTTLChannel();
        void SetTTLChannel(int v);
        void DecTTLChannel();
        int GetLimitUpload();
        void SetLimitUpload(int limitUpload);
        PairStrInt GetPairStrInt();
        //ECM

        void SetMode(PeerModes mode);
        PeerModes GetMode();
        void SetChunkMap(ChunkUniqueID chunkMapHead, boost::dynamic_bitset<>x);
        bool GetChunkMapPos(int i) const;
        uint32_t GetChunkMapSize() const;
        void IncPendingRequests();
        void DecPendingRequests();
        int  GetPendingRequests();
        void SetDelay(float value);
        float GetDelay();
        void SetUploadScore(int value);
        int  GetUploadScore();
        
        int GetSizePeerListOutInformed ();
        int GetSizePeerListOutInformed_FREE ();
        void SetSizePeerListOutInformed(int sizePeerListOutInformed);
        void SetSizePeerListOutInformed_FREE(int sizePeerListOutInformed_FREE);

        int GetSizePeerListOutOld ();
        int GetSizePeerListOutOld_FREE ();
        void SetSizePeerListOutOld(int sizePeerListOutNew);
        void SetSizePeerListOutOld_FREE(int sizePeerListOutNew_FREE);

        void SetHit_count(uint16_t hit_count);
        void DecHit_count();
        uint16_t GetHit_count();


        void Inc_peerSentChunks (int value = 1);
        uint32_t Get_peerSentChunks();
        void Set_peerSentChunks(uint32_t value);

        ChunkUniqueID GetChunkMapHead();
        void SetChunkMapHead(ChunkUniqueID chunkMapHead);
       
        friend bool operator==(const PeerData &a, const PeerData &b) {return a.peer==b.peer;};
        friend bool operator!=(const PeerData &a, const PeerData &b) {return a.peer!=b.peer;};
        friend std::ostream& operator<<(std::ostream& os, const PeerData& pd);
        
    private:
        //PeerId
        Peer* peer;
        PeerModes mode;

        //PartnerChunkMap
        HeadedBitset chunkMap;
        
        //TimeToLive of the partnership or request
        //ECM
        int ttlIn;
        int ttlOut;
        int ttlout_free;
        int ttlChannel;
        uint32_t peerSentChunks;    // pontua clientes com maior pedidos por dados
        uint16_t hit_count;         // contador de contatos de peers para calculo de newOut e newOutFree
        //ECM
        
        //Peer classification technologies =D
        int uploadScore;
        int pendingRequests;
        int quality;
        float delay;
};
#endif // PEERDATA_H_INCLUDED
